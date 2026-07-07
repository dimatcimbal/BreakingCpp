SHELL  := /bin/bash
BINARY := ../build/1231-DoublyLinkedList/1231-DoublyLinkedList

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@$(BINARY) | \
		diff - <(printf "1\n2\n3\n4\n") \
		&& echo "PASS: case 1"
