# Class Hierarchy

A minimal starting point for exploring class hierarchies (base/derived classes, inheritance, virtual dispatch). The current stub only prints a confirmation message; the hierarchy itself is built out in later revisions of this lab.

## Access modifiers and inheritance

The resulting access of a base class member inside a subclass depends on both how the member is declared in the base class and how the subclass inherits from it:

| When the component is declared as: | When the class is inherited as: | The resulting access inside the subclass is: |
|---|---|---|
| `public` | `public` | `public` |
| `protected` | `public` | `protected` |
| `private` | `public` | none |
| `public` | `protected` | `protected` |
| `protected` | `protected` | `protected` |
| `private` | `protected` | none |
| `public` | `private` | `private` |
| `protected` | `private` | `private` |
| `private` | `private` | none |

## Expected output

```
done
```
