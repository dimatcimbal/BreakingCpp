SHELL  := /bin/bash
BINARY := ../build/1224-SinglyLinkedList-p1/1224-SinglyLinkedList-p1

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@$(BINARY) | \
		diff - <(printf "4\n3\n2\n1\n") \
		&& echo "PASS: case 1"
