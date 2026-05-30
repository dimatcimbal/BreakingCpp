# Restricting Access

One important aspect of object-oriented programming is **data encapsulation** — protecting an object's internal state from unintended modification.

Look at the starter code: nothing prevents a caller from setting a negative side length, and `area` can fall out of sync with `side`. Your task is to fix this by applying proper access control.

## Tasks

1. Mark `side` and `area` as `private`.
2. Add a public `set_side(double side)` method that updates both fields atomically and ignores values less than or equal to zero.
3. Convert the free `print` function into a public `print()` method on `Square`.
