# Points in 2D: Part 2

A `Line2D` class representing a line in two-dimensional space, constructed from two `Point2D` objects.

A line is defined by slope `a` and y-intercept `b` such that `y = ax + b`.

The program reads two points and prints the line they define.

## Formulae

- Slope: `a = (y2 - y1) / (x2 - x1)`
- Y-intercept: `b = y1 - a * x1`

## Output format

```
y = [a]x + [b]    — if b >= 0
y = [a]x - [b]    — if b < 0
```

## Notes

- `Point2D` stores `x` and `y` as `double` coordinates
- `Line2D` takes two `Point2D` objects in its constructor

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
