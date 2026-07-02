SHELL  := /bin/bash
BINARY := ../build/1214-FlightBooking-p2/1214-FlightBooking-p2

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "%s\n%s\n%s\n%s\n%s\n%s\n%s\n" "create 101 400" "create 307 180" "add 101 404" "add 307 9" "cancel 101 200" "delete 101" "quit" | $(BINARY) | \
		diff - <(printf "No flights in the system\n\nFlight 101 : 0/400 (0%%) seats reserved\n\nFlight 101 : 0/400 (0%%) seats reserved\nFlight 307 : 0/180 (0%%) seats reserved\n\nFlight 101 : 404/400 (101%%) seats reserved\nFlight 307 : 0/180 (0%%) seats reserved\n\nFlight 101 : 404/400 (101%%) seats reserved\nFlight 307 : 9/180 (5%%) seats reserved\n\nFlight 101 : 204/400 (51%%) seats reserved\nFlight 307 : 9/180 (5%%) seats reserved\n\nFlight 307 : 9/180 (5%%) seats reserved\n\n") \
		&& echo "PASS: case 1"
	@printf "%s\n%s\n%s\n%s\n%s\n%s\n%s\n" "add 101 404" "create 101 400" "add 101 500" "delete 101" "cancel 101 200" "delete 101" "quit" | $(BINARY) | \
		diff - <(printf "No flights in the system\n\nCannot perform this operation: flight 101 not found\nNo flights in the system\n\nFlight 101 : 0/400 (0%%) seats reserved\n\nCannot perform this operation: capacity reached\nFlight 101 : 0/400 (0%%) seats reserved\n\nNo flights in the system\n\nCannot perform this operation: flight 101 not found\nNo flights in the system\n\nCannot perform this operation: flight 101 not found\nNo flights in the system\n\n") \
		&& echo "PASS: case 2"
