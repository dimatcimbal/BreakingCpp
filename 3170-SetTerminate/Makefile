SHELL  := /bin/bash
BINARY := ../build/3170-SetTerminate/3170-SetTerminate

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@$(BINARY) | \
		diff - <(printf "An exception escaped a noexcept function. Terminating.\n") \
		&& echo "PASS: case 1"
