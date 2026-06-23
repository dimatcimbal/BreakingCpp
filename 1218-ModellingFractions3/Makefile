SHELL  := /bin/bash
BINARY := ../build/1218-ModellingFractions3/1218-ModellingFractions3

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "3/4\n1/3\n" | $(BINARY) | \
		diff - <(printf "3/4 > 1/3\n") \
		&& echo "PASS: case 1"
	@printf "7/4\n-6/10\n" | $(BINARY) | \
		diff - <(printf "%s\n" "1 3/4 > -6/10") \
		&& echo "PASS: case 2"
