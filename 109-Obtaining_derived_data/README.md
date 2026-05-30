# Obtaining Derived Data

Encapsulation isn't only about protecting data on the way in — it also shapes how computed values are exposed on the way out.

The area of a square is derived from its side. There are three common strategies for surfacing such a value:

| Strategy | How it works | Trade-off |
|----------|-------------|-----------|
| **Eager** | Recalculate on every `set_side` call | Always fresh; wasteful for expensive computations |
| **Ad hoc** | Calculate on every `get_area` call, store nothing | Simple; also wasteful if called frequently |
| **Lazy** | Recalculate only when the side has changed since the last call | Best of both; requires a dirty flag |

## Tasks

Implement the two classes defined in the starter code:

1. **`AdHocSquare`** — compute area inside `get_area()` each time it is called; do not store it.
2. **`LazySquare`** — use a `side_changed` flag to recalculate area only when necessary; return the cached value otherwise.
