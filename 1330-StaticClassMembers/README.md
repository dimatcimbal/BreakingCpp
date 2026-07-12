# Static Class Members

A `static` data member belongs to the class itself, not to any one instance — there is exactly one copy of it, shared by every object of that type. It is created once, before `main` runs, and destroyed once, after `main` returns — the same lifetime as any other static storage duration variable, just scoped to a class instead of a namespace.

`Counter` uses a static data member to track how many `Counter` instances currently exist. Every constructor call increments it; every destructor call decrements it. A `static` member function exposes the current count without needing an instance to call it through — static member functions have no implicit `this`, so they can only access other static members.

## Methods

| Method | Description |
|--------|-------------|
| `Counter()` | Constructs an instance and increments the shared count |
| `~Counter()` | Destroys an instance and decrements the shared count |
| `static int get_count()` | Returns the current number of live instances |

## Expected output

Construct three `Counter` instances in nested scopes, printing the count after each construction and destruction as they go out of scope:

```
count = 1
count = 2
count = 3
count = 2
count = 1
count = 0
```

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
