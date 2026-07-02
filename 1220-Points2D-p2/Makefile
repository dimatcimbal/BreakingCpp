SHELL  := /bin/bash
BINARY := ../build/1220-Points2D-p2/1220-Points2D-p2

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "%s\n%s\n" "0 0" "3 6" | $(BINARY) | \
		diff - <(printf "%s\n" "y = 2x + 0") \
		&& echo "PASS: case 1"
	@printf "%s\n%s\n" "2 2" "-2 0" | $(BINARY) | \
		diff - <(printf "%s\n" "y = 0.5x + 1") \
		&& echo "PASS: case 2"
	@printf "%s\n%s\n" "-1 1" "2 -4" | $(BINARY) | \
		diff - <(printf "%s\n" "y = -1.66667x - 0.666667") \
		&& echo "PASS: case 3"
