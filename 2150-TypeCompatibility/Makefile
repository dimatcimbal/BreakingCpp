SHELL  := /bin/bash
BINARY := ../build/2150-TypeCompatibility/2150-TypeCompatibility

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@$(BINARY) | \
		diff - <(printf "Spike: I'm running\nSpike: Meow! Meow!\nTom: I'm running\nTom: Woof! Woof!\n") \
		&& echo "PASS: case 1"
