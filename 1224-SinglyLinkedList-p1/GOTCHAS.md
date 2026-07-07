# C++ Gotchas — Singly Linked List: Part 1

### 1. Raw pointer default initialization leaves an indeterminate value

The compiler-generated default constructor **default-initializes** members. For a raw pointer, that means an indeterminate value — whatever garbage was in that memory location. Reading it is undefined behavior.

An explicit member initializer sets it to a known safe state:

```cpp
List::List() : head(nullptr) {}  // safe — head is guaranteed nullptr
```

If `head` were `std::unique_ptr<Node>` instead, the compiler-generated default constructor would be correct by default — `unique_ptr`'s own default constructor guarantees `nullptr`. That is one of the reasons `unique_ptr` is safer than raw pointers.

### 2. Copy and move assignment operators must return `T&`

The copy and move assignment operators must return `T&`, not `T`. Returning by value would slice the object and is never correct. Even when `= delete`, the signature should be right — static analyzers and documentation readers check it.

```cpp
Node& operator=(const Node& other) = delete;
Node& operator=(Node&& other) = delete;
```

The same rule applies to any class: copy/move assignment always returns `T&`.

### 3. `std::cerr` behaviour differs across platforms

`stdout` and `stderr` are independent file descriptors on macOS/Linux — writing to `std::cerr` never affects exit codes or triggers errors. Test pipelines like `$(BINARY) | diff -` only capture `stdout`, so `std::cerr` output goes straight to the terminal unnoticed.

On PowerShell/Windows the situation is different — stderr output is captured into the error stream and can abort scripts if `$ErrorActionPreference = 'Stop'` is set, which is common in CI environments.
