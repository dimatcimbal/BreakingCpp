# The auto Keyword

All variables belong to one of two categories:

- **Automatic variables** — created and destroyed, sometimes repeatedly, automatically during program execution
- **Static variables** — existing continuously for the whole program execution

C and C++ treat every variable as automatic by default unless it is declared `static`. The `auto` storage-class keyword — inherited from C — exists to mark a variable as automatic explicitly, though it is rarely used today since automatic is already the default.

`fun` declares a local `int var` initialized to `99` on every call. Because the variable is automatic, it is created fresh each time `fun` runs and destroyed when `fun` returns — no state carries over between calls.

## Expected output

`main` calls `fun` five times in a loop. Each call prints the pre-incremented value of `var`:

```
var = 100
var = 100
var = 100
var = 100
var = 100
```

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
