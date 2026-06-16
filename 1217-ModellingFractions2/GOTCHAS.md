# C++ Gotchas — Modelling Fractions 2

### 1. Parsing input with a custom delimiter using `std::istream` and `std::streambuf`

To parse input with non-standard delimiters, combine a custom `std::streambuf` with
`std::istream` — the streambuf controls which characters are visible, the istream handles
type conversion:

- `std::streambuf` — character supply: decides what the stream sees
- `std::istream` — type parsing: converts characters to `int`, `double`, etc.

They are connected through a pointer: `std::istream` holds a `std::streambuf*` and calls
`sbumpc()` / `sgetc()` on it for every character it needs:

```
std::istream::operator>>(int&)
    │  needs characters
    ▼
std::streambuf::sgetc()
    │  get area empty — calls underflow()
    ▼
DelimBuf::underflow()       ← our override
    │  reads from source, skips '/', exposes next char via setg()
    ▼
std::istream parses digits, converts to int
```

### 2. Custom `std::streambuf` — intercepting character flow via `underflow()`

Since `std::istream` delegates all character access to `std::streambuf`, controlling what
the stream sees is done by subclassing `std::streambuf` and overriding `underflow()` —
the virtual method the base class calls when the get area is empty and more characters are needed.

`DelimBuf{std::string, '/'}` treats `/` as a delimiter by skipping it in `underflow()`. From `std::istream`'s
perspective, `/` never exists — it only sees what `underflow()` exposes:

```cpp
struct DelimBuf : std::streambuf {
    int_type underflow() override {
        int_type c = src->sbumpc();
        while (c == delim) c = src->sbumpc();  // skip delimiter transparently
        if (c == traits_type::eof()) return traits_type::eof();
        buf = traits_type::to_char_type(c);
        setg(&buf, &buf, &buf + 1);
        return c;
    }
};
```

### 3. `std::streambuf::setg(begin, current, end)` — defining the get area

The get area is a character buffer with three pointers that sits between `std::istream` and
`underflow()`. It exists to avoid a virtual call for every character — instead of calling
`underflow()` each time, `std::istream` reads directly from the buffer until it's empty,
then calls `underflow()` once to refill it.

In practice `std::filebuf` fills it with 4096 bytes at a time — `underflow()` is called once
per chunk. `DelimBuf` uses size 1 — so `underflow()` is called for every character, which
eliminates the batching benefit but is still required because it's the contract `std::streambuf` defines.

The three pointers define the window:

```
Memory:  [ 'H' | 'e' | 'l' | 'l' | 'o' ]
           ^           ^               ^
         eback()     gptr()          egptr()
         (begin)    (current)         (end)
```

- `eback()` — start of the buffer
- `gptr()` — next character to hand to `std::istream`
- `egptr()` — one past the last available character

`sgetc()` checks: if `gptr() < egptr()` return `*gptr()` directly (fast path, no virtual call).
If `gptr() == egptr()` call `underflow()` to refill (slow path).

`setg(&buf, &buf, &buf + 1)` is the minimum required to satisfy this — it tells `sgetc()`
one character is available at `buf`. Without it `gptr() == egptr()` is always true and
`underflow()` would loop infinitely.

### 4. `std::istream::clear()` — resetting stream state after `eof`

When `underflow()` returns `eof()`, `std::istream` sets `eofbit` and `failbit`. These are
state bits on `std::istream` — `std::streambuf` has no knowledge of them:

| Bit | Meaning |
|-----|---------|
| `std::istream::goodbit` | no errors — all operations proceed normally |
| `std::istream::eofbit`  | end of stream reached |
| `std::istream::failbit` | last extraction failed (wrong type or eof) |
| `std::istream::badbit`  | unrecoverable stream corruption |

**Without `clear()` — short-circuit path:**
```
delim_stream >> val
    │
    ▼
std::istream::operator>>(int&)
    │  checks good() — eofbit set
    └─ returns immediately, val unchanged  ← never reaches streambuf
```

**After `clear()` — normal path:**
```
delim_stream.clear()       // resets eofbit + failbit → goodbit
delim_stream >> val
    │
    ▼
std::istream::operator>>(int&)
    │  checks good() — goodbit set → proceeds
    ▼
std::streambuf::sgetc()
    │  get area empty — calls underflow()
    ▼
DelimBuf::underflow()
    │  reads next char from iss, exposes via setg()
    ▼
std::istream reads digits, converts to int
```

Key insight: `clear()` only resets `std::istream`'s state bits — `DelimBuf` has no
knowledge of them. It simply allows `operator>>` to proceed past the `good()` check
and reach `sgetc()` again.
