# Modelling Fractions: Part 1

A class representing non-integer numbers as fractions, with both textual and floating-point representations.

Input is given in the form `[numerator] / [denominator]`.

## Output format

| Case | Input | Output |
|------|-------|--------|
| Proper fraction | `3 / 4` | `3/4 is 0.75 in decimal` |
| Improper fraction | `7 / -4` | `-1 3/4 is -1.75 in decimal` |
| Whole number | `8 / 4` | `2 is 2.0 in decimal` |

## Notes

- Display the whole part separately for improper fractions: `7/4` → `1 3/4`
- Signs: `-3/4` and `3/-4` both display as `-3/4` — the sign belongs to the numerator
- The denominator will never be `0`
- Whole numbers display with a `.0` decimal suffix: `2 is 2.0 in decimal`

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
