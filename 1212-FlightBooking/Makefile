SHELL  := /bin/bash
BINARY := ../build/1212-FlightBooking/1212-FlightBooking

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "100\n50\nquit\n" | $(BINARY) | \
		diff - <(echo "Flight 1 : 50/100 (50%) seats reserved") \
		&& echo "PASS: 50/100"
	@printf "180\n200\nquit\n" | $(BINARY) | \
		diff - <(echo "Flight 1 : 200/180 (111%) seats reserved") \
		&& echo "PASS: 200/180"
	@printf "100\n50\nadd 4\ncancel 200\nquit\n" | $(BINARY) | \
		diff - <(printf "Flight 1 : 50/100 (50%%) seats reserved\nFlight 1 : 54/100 (54%%) seats reserved\nCannot perform this operation\nFlight 1 : 54/100 (54%%) seats reserved\n") \
		&& echo "PASS: case 1"
	@printf "180\n200\nadd 1\nquit\n" | $(BINARY) | \
		diff - <(printf "Flight 1 : 200/180 (111%%) seats reserved\nCannot perform this operation\nFlight 1 : 200/180 (111%%) seats reserved\n") \
		&& echo "PASS: case 2"
