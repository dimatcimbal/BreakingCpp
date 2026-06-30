SHELL  := /bin/bash
BINARY := ../build/1212-FlightBooking/1212-FlightBooking

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "%s\n%s\n%s\n" "100" "50" "quit" | $(BINARY) | \
		diff - <(printf "%s\n" "Flight 1 : 50/100 (50%) seats reserved") \
		&& echo "PASS: 50/100"
	@printf "%s\n%s\n%s\n" "180" "200" "quit" | $(BINARY) | \
		diff - <(printf "%s\n" "Flight 1 : 200/180 (111%) seats reserved") \
		&& echo "PASS: 200/180"
	@printf "%s\n%s\n%s\n%s\n%s\n" "100" "50" "add 4" "cancel 200" "quit" | $(BINARY) | \
		diff - <(printf "Flight 1 : 50/100 (50%%) seats reserved\nFlight 1 : 54/100 (54%%) seats reserved\nCannot perform this operation\nFlight 1 : 54/100 (54%%) seats reserved\n") \
		&& echo "PASS: case 1"
	@printf "%s\n%s\n%s\n%s\n" "180" "200" "add 1" "quit" | $(BINARY) | \
		diff - <(printf "Flight 1 : 200/180 (111%%) seats reserved\nCannot perform this operation\nFlight 1 : 200/180 (111%%) seats reserved\n") \
		&& echo "PASS: case 2"
