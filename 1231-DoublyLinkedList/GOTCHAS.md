# C++ Gotchas — Doubly Linked List

### 1. The copy and move constructors must be written in terms of the class itself

```cpp
Node(const Node& other) = delete;
Node& operator=(const Node& other) = delete;
Node(Node&& other) = delete;
Node& operator=(Node&& other) = delete;
```

When customizing the copy/move constructors for a class template like `Node<T>`, it's easy to accidentally write them in terms of the template parameter `T` instead of the class itself — for example taking `const T&` where `const Node&` was intended. With `T = int`, that parameter becomes `const int&`, so the constructor is really just a second overload of the value constructor rather than a copy constructor. The real value constructor `Node(T value)` and this overload now both accept a plain `int` lvalue equally well, so the compiler reports any such call as ambiguous — even when the second overload is deleted. Deletion only takes effect *after* a candidate is selected; it does not remove the candidate from overload resolution. The same ambiguity would occur if the constructor were given a real definition instead of `= delete`.

Using the template parameter only where the class name is needed correctly defines the copy/move constructors for a `Node<T>` object while leaving the single value constructor unambiguous.
