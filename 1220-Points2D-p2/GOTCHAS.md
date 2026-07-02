# C++ Gotchas — Points in 2D: Part 2

### 1. Free `operator>>` and `operator<<` for custom types

To support `std::cin >> p` and `std::cout << p`, define free functions that take streams
by reference and return the stream to enable chaining (`cin >> p1 >> p2`):

```cpp
std::istream& operator>>(std::istream& in, Point2D& p) {
    // read into p...
    return in;
}

std::ostream& operator<<(std::ostream& out, const Point2D& p) {
    out << p.to_string();
    return out;
}
```

Streams are not copyable — always pass and return by reference.

### 2. Use a pointer array to fill struct members in a loop

To assign to multiple private members by index, build an array of pointers and dereference:

```cpp
double* values[] = {&p.x, &p.y};
for (size_t i = 0; ...; i++) {
    *values[i] = val;
}
```

### 3. Grant access to private members with `friend class`

When two tightly coupled classes need access to each other's private members,
use `friend class` — it grants all methods of the named class (including constructors)
access to private members:

```cpp
class Point2D {
    friend class Line2D;  // Line2D constructors and methods can access x and y
    double x, y;
};
```
