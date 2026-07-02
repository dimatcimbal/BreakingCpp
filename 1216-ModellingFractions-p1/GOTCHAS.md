# C++ Gotchas — Modelling Fractions

### 1. Parsing integers from a string token — exception-free with `std::istringstream >>`

`std::stoi` throws on invalid input. The exception-free alternative is to wrap the token
in a `std::istringstream` and use `>>` — it returns the stream itself, which converts to
`false` on failure:

```cpp
std::string token = "42";
int val;
std::istringstream ss{token};
if (ss >> val) {
    // val is valid
}
```

### 2. Using a pointer array to fill struct members in a loop

To assign to multiple struct members by index, build an array of pointers to them and dereference:

```cpp
Fraction f;
int* values[] = {&f.numerator, &f.denominator};

for (int i = 0; i < 2; i++) {
    *values[i] = some_value;  // writes directly into f.numerator or f.denominator
}
```

The key is `*values[i]` — `values[i]` is an `int*`, so dereferencing it with `*` gives the `int&` needed to assign.

### 3. `std::initializer_list` does not support `operator[]`

`std::initializer_list` is a lightweight read-only view over a temporary array created by
a brace-initializer `{...}`. It exists to make brace-initialization work uniformly across
user-defined types — `std::vector` is the canonical example:

```cpp
// inside std::vector (simplified):
template<typename T>
class vector {
public:
    vector(std::initializer_list<T> list) {
        for (const T& val : list) {
            push_back(val);
        }
    }
};

// at call site:
std::vector<int> v = {1, 2, 3};  // calls vector(initializer_list<int>{1, 2, 3})
```

`std::initializer_list` is a view — it doesn't own its data, it just points to a temporary array with no mutation API:

```cpp
auto arr = {&f.numerator, &f.denominator};  // ❌ — deduces to std::initializer_list<int*>
arr[0];                                      // ❌ — no operator[], no random access
arr[0] = nullptr;                            // ❌ — read-only

for (auto* p : arr) { ... }                  // ✅ — forward iteration only
```

For indexed access or mutation, use a plain C array or `std::array`:
```cpp
int* arr[] = {&f.numerator, &f.denominator};               // ✅ plain C array
std::array<int*, 2> arr = {&f.numerator, &f.denominator};  // ✅ std::array
arr[0];  // ✅ operator[] supported on both
```
