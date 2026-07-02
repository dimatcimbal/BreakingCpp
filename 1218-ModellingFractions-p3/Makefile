SHELL  := /bin/bash
BINARY := ../build/1218-ModellingFractions-p3/1218-ModellingFractions-p3

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "%s\n%s\n" "3/4" "1/3" | $(BINARY) | \
		diff - <(printf "%s\n" "3/4 > 1/3") \
		&& echo "PASS: case 1"
	@printf "%s\n%s\n" "7/4" "-6/10" | $(BINARY) | \
		diff - <(printf "%s\n" "1 3/4 > -6/10") \
		&& echo "PASS: case 2"
