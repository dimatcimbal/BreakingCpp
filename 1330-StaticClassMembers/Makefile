SHELL  := /bin/bash
BINARY := ../build/1330-StaticClassMembers/1330-StaticClassMembers

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@$(BINARY) | \
		diff - <(printf "The count is 1\nthe count is 2\nthe count is 3\nthe count is 0\n") \
		&& echo "PASS: case 1"
