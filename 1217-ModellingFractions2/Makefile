SHELL  := /bin/bash
BINARY := ../build/1217-ModellingFractions2/1217-ModellingFractions2

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "3/4\n1/3\n" | $(BINARY) | \
		diff - <(printf "3/4 + 1/3 = 1 1/12\n3/4 - 1/3 = 5/12\n3/4 * 1/3 = 1/4\n3/4 / 1/3 = 2 1/4\n") \
		&& echo "PASS: case 1"
	@printf "7/4\n-6/10\n" | $(BINARY) | \
		diff - <(printf "%s\n" "1 3/4 + -6/10 = 1 3/20" "1 3/4 - -6/10 = 2 7/20" "1 3/4 * -6/10 = -1 1/20" "1 3/4 / -6/10 = -2 11/12") \
		&& echo "PASS: case 2"
