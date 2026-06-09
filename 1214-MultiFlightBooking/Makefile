SHELL  := /bin/bash
BINARY := ../build/1214-MultiFlightBooking/1214-MultiFlightBooking

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "create 101 400\ncreate 307 180\nadd 101 404\nadd 307 9\ncancel 101 200\ndelete 101\nquit\n" | $(BINARY) | \
		diff - <(printf "No flights in the system\n\nFlight 101 : 0/400 (0%%) seats reserved\n\nFlight 101 : 0/400 (0%%) seats reserved\nFlight 307 : 0/180 (0%%) seats reserved\n\nFlight 101 : 404/400 (101%%) seats reserved\nFlight 307 : 0/180 (0%%) seats reserved\n\nFlight 101 : 404/400 (101%%) seats reserved\nFlight 307 : 9/180 (5%%) seats reserved\n\nFlight 101 : 204/400 (51%%) seats reserved\nFlight 307 : 9/180 (5%%) seats reserved\n\nFlight 307 : 9/180 (5%%) seats reserved\n\n") \
		&& echo "PASS: case 1"
	@printf "add 101 404\ncreate 101 400\nadd 101 500\ndelete 101\ncancel 101 200\ndelete 101\nquit\n" | $(BINARY) | \
		diff - <(printf "No flights in the system\n\nCannot perform this operation: flight 101 not found\nNo flights in the system\n\nFlight 101 : 0/400 (0%%) seats reserved\n\nCannot perform this operation: capacity reached\nFlight 101 : 0/400 (0%%) seats reserved\n\nNo flights in the system\n\nCannot perform this operation: flight 101 not found\nNo flights in the system\n\nCannot perform this operation: flight 101 not found\nNo flights in the system\n\n") \
		&& echo "PASS: case 2"
