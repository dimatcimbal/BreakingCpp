SHELL  := /bin/bash
BINARY := ../build/2000-ClassHierarchy/2000-ClassHierarchy

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@$(BINARY) | \
		diff - <(printf "done\n") \
		&& echo "PASS: case 1"
