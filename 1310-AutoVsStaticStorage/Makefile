SHELL  := /bin/bash
BINARY := ../build/1310-AutoVsStaticStorage/1310-AutoVsStaticStorage

.PHONY: test

test:
	@printf "Tests $(BINARY)\n"
	@$(BINARY) | \
		diff - <(printf "automatic = 100, static = 100\nautomatic = 100, static = 101\nautomatic = 100, static = 102\nautomatic = 100, static = 103\nautomatic = 100, static = 104\n") \
		&& echo "PASS: case 1"
