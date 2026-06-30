SHELL  := /bin/bash
BINARY := ../build/1217-ModellingFractions2/1217-ModellingFractions2

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "%s\n%s\n" "3/4" "1/3" | $(BINARY) | \
		diff - <(printf "3/4 + 1/3 = 1 1/12\n3/4 - 1/3 = 5/12\n3/4 * 1/3 = 1/4\n3/4 / 1/3 = 2 1/4\n") \
		&& echo "PASS: case 1"
	@printf "%s\n%s\n" "7/4" "-6/10" | $(BINARY) | \
		diff - <(printf "%s\n" "1 3/4 + -6/10 = 1 3/20" "1 3/4 - -6/10 = 2 7/20" "1 3/4 * -6/10 = -1 1/20" "1 3/4 / -6/10 = -2 11/12") \
		&& echo "PASS: case 2"
