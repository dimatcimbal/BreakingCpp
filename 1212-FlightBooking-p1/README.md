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


## Task 2 - Booking methods

Let's continue working on our booking system.

You may remember in our last task that we had no limit on the number of reserved seats.

Airlines often allow the overbooking of flights, expecting that some passengers will not make it.

Modify the constructor so that it will not allow more than 105% reservation of the total capacity.

Also for a negative number of reservations, set the number to 0.

We might also want to be able to add new reservations or cancel them. Provide a way for the user to do this via a simple interface.

The command "add [n]" will try to add n reservations to the flight.
The command "cancel [n]" will try to cancel n reservations from the flight.
If an operation fails for any reason, the program will issue the message "Cannot perform this operation"
The command "quit" will stop execution of the program.

## C++ Gotchas

See [GOTCHAS.md](GOTCHAS.md).
