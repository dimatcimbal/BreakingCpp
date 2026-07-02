# Multi-Flight Booking System

Let's finish working on our booking system by managing multiple flights.

The program maintains a list of up to **10 flights** and responds to the following commands:

| Command | Description |
|---------|-------------|
| `create [id] [cap]` | Create a new empty flight with ID `[id]` and capacity `[cap]` |
| `delete [id]` | Remove the flight with ID `[id]` |
| `add [id] [n]` | Add `n` reservations to flight `[id]` |
| `cancel [id] [n]` | Cancel `n` reservations from flight `[id]` |
| `quit` | Stop execution |

After each command, print the status of all flights currently in the system. If no flights exist, print `No flights in the system`.

If an operation fails for any reason, print `Cannot perform this operation`. You may add a more specific message to identify why it failed.

## Notes

- Flight ID `0` is not valid — a slot with ID `0` is considered empty.
- Add a `getId()` accessor to `FlightBooking` to look up flights by ID.
- Use the code from `1212-FlightBooking` as a starting point.

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
