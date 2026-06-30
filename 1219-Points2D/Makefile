SHELL  := /bin/bash
BINARY := ../build/1219-Points2D/1219-Points2D

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "0 0\n3 4\n" | $(BINARY) | \
		diff - <(printf "5\n") \
		&& echo "PASS: case 1"
	@printf "9, 16\n4, 4\n" | $(BINARY) | \
		diff - <(printf "13\n") \
		&& echo "PASS: case 2"
	@printf "%s\n%s\n" "-3 -6.7" "-8.5 9" | $(BINARY) | \
		diff - <(printf "16.6355042\n") \
		&& echo "PASS: case 3"
