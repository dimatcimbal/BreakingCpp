# Flight Booking

Our systems record an identification number, the total capacity, and the number of reserved seats for every flight booking.

## Task 1 — Status report

Implement `FlightBooking` so it prints a status report in this exact format:

```
Flight [id] : [reserved]/[capacity] ([percentage]%) seats taken
```

For example, 45 reserved seats on a flight with a capacity of 200 would print:

```
Flight 1 : 45/200 (22%) seats taken
```

For now, there is no restriction on the number of reserved seats — that comes later.

## Notes

- The percentage should be rounded to the nearest whole number.
- Implement the constructor to save all three arguments to their respective members.
- Implement `printStatus()` to produce the report above.
