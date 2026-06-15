SHELL  := /bin/bash
BINARY := ../build/1216-ModellingFractions/1216-ModellingFractions

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@printf "3/4\n" | $(BINARY) | \
		diff - <(printf "3/4 is 0.75 in decimal\n") \
		&& echo "PASS: 3/4"
	@printf "7/-4\n" | $(BINARY) | \
		diff - <(printf "%s\n" "-1 3/4 is -1.75 in decimal") \
		&& echo "PASS: 7/-4"
	@printf "8/4\n" | $(BINARY) | \
		diff - <(printf "2 is 2.0 in decimal\n") \
		&& echo "PASS: 8/4"
