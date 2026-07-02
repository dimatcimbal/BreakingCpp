# Modelling Fractions: Part 2

Extends the `Fraction` class from Part 1 with arithmetic operations and reduction to lowest terms.

The program reads two fractions and prints the result of all four operations.

## Output format

```
[a] + [b] = [result]
[a] - [b] = [result]
[a] * [b] = [result]
[a] / [b] = [result]
```

For example, given `3/4` and `1/3`:
```
3/4 + 1/3 = 1 1/12
3/4 - 1/3 = 5/12
3/4 * 1/3 = 1/4
3/4 / 1/3 = 2 1/4
```

## Notes

- All results must be reduced to lowest terms — use the Euclidean algorithm (GCD)
- Display format follows Part 1: whole part separated for improper fractions, sign on numerator
- Input format: `[numerator] / [denominator]` (two lines)

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
