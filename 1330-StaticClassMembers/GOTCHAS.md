# C++ Gotchas — Static Class Members

### 1. Static data members need an out-of-class definition (pre-C++17)

Declaring a static data member inside the class body is only a declaration, not a definition:

```cpp
class Counter {
    static int instance_count;  // declaration only
};
```

Before C++17, this needed a matching definition in exactly one `.cpp` file:

```cpp
int Counter::instance_count = 0;  // definition — gives it storage
```

Without it, the program compiles but fails to link the first time something actually uses `instance_count`, with an error like "undefined reference to `Counter::instance_count`" — confusing because the mistake is in a header, but the error surfaces at link time, in a different file, often far from the class definition itself.

C++17 introduced `inline` static data members, which fold declaration and definition into a single line inside the class body (`static inline int instance_count = 0;`), removing the need for the separate out-of-class definition. Older or mixed-standard codebases will still show the two-step pattern.

### 2. Static member functions have no `this`

A regular (non-static) member function receives an implicit `this` pointer to the instance it was called on — that's how `get_count()` could read `instance_count` even without writing `this->instance_count` explicitly. A `static` member function has no such pointer: it isn't associated with any particular instance, only with the class itself.

This means a static member function can only access other static members — it cannot read or write non-static data members, and it cannot call non-static member functions, because there is no instance for `this` to refer to. It can still be called through an instance (`counter.get_count()`), but it is more commonly called through the class name directly (`Counter::get_count()`), which makes the absence of an instance explicit at the call site.
