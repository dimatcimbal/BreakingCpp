SHELL  := /bin/bash
BINARY := ../build/1212-FlightBooking/1212-FlightBooking

.PHONY: test

test:
	@printf "100\n50\n" | $(BINARY) | \
		diff - <(echo "Flight 1 : 50/100 (50%) seats reserved") \
		&& echo "PASS: 50/100"
	@printf "180\n200\n" | $(BINARY) | \
		diff - <(echo "Flight 1 : 180/200 (111%) seats reserved") \
		&& echo "PASS: 180/200"
