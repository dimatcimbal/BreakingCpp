# Set Terminate

Demonstrates `std::set_terminate()`, the modern replacement for the pre-C++17 `unexpected()`/`set_unexpected()` mechanism. Dynamic exception specifications and `unexpected()` were deprecated in C++11 and removed entirely in C++17 -- since then, any exception with no matching handler, or one that tries to escape a function marked `noexcept`, calls `std::terminate()` directly.

`level()` always throws a `std::string`. `function()` is declared `noexcept` and calls `level()`; because of that `noexcept`, the exception cannot propagate past `function()` -- `std::terminate()` runs immediately, even though `main()` wraps the call to `function()` in a `try`/`catch (const std::string&)`. The `catch` clause never gets a chance to run: termination happens before unwinding reaches it.

`std::set_terminate(lastchance)` installs `lastchance()` as the handler that runs when `std::terminate()` fires. Like the old `unexpected()` handler, it cannot rescue the program -- it can only perform last-breath diagnostics or cleanup before the process aborts. `lastchance()` prints its message flushed with `std::endl` (rather than `"\n"`), since the `std::abort()` it calls afterward does not flush buffered stdout, and then aborts explicitly, since returning normally from a terminate handler is undefined behavior.

## Expected output

```
An exception escaped a noexcept function. Terminating.
```

The program then aborts abnormally; `"Caught!"` never prints.
