# Type Compatibility

Explores casting between related pointer types in a class hierarchy. `Pet` is the common base for `Dog` and `Cat`; both derived classes add a `MakeSound` method that `Pet` doesn't have, so calling it through a `Pet*` requires a cast down to the concrete type first.

The exercise as written abuses `static_cast`: it casts a `Pet*` that actually points at a `Dog` down to `Cat*` (and vice versa), because `static_cast` performs no runtime type check — it trusts the programmer's claim about the pointer's real type, even when that claim is wrong. The result is each pet making the wrong sound.

## Expected output

```
Spike: I'm running
Spike: Meow! Meow!
Tom: I'm running
Tom: Woof! Woof!
```
