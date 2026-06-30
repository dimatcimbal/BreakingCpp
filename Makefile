BUILD_TYPE ?= Debug
BUILD_DIR  ?= build

.PHONY: help configure build release clean rebuild format format-check test

help: ## Show available targets
	@echo "LabsCpp — Build Commands"
	@echo ""
	@echo "Usage: make <target> [options]"
	@echo ""
	@grep -E '^[a-zA-Z_-]+:.*?## .*$$' $(MAKEFILE_LIST) | \
		awk 'BEGIN {FS = ":.*?## "}; {printf "  %-18s %s\n", $$1, $$2}'
	@echo ""
	@echo "Options:"
	@echo "  BUILD_TYPE=<type>  Debug|Release  (default: Debug)"
	@echo "  BUILD_DIR=<dir>    build directory (default: build)"
	@echo "  TARGET=<name>      build a single target, e.g. TARGET=107"

configure: ## Configure with Ninja
	cmake -B $(BUILD_DIR) -S . -G Ninja -DCMAKE_BUILD_TYPE=$(BUILD_TYPE) -DCMAKE_EXPORT_COMPILE_COMMANDS=ON
	ln -sf $(BUILD_DIR)/compile_commands.json .

build: configure ## Build all labs (Debug)
	cmake --build $(BUILD_DIR) $(if $(TARGET),--target $(TARGET)) -j
	@echo "BUILD DONE"

release: ## Build all labs in Release mode
	$(MAKE) BUILD_TYPE=Release build

clean: ## Remove build artifacts
	rm -rf $(BUILD_DIR) compile_commands.json

rebuild: clean build ## Clean then build from scratch

format: ## Format all source files with clang-format
	@find . -name '*.cpp' -o -name '*.hpp' -o -name '*.h' | \
		grep -v build | while read f; do \
			if ! clang-format --dry-run --Werror "$$f" 2>/dev/null; then \
				clang-format -i "$$f"; \
				echo "Formatted: $$f"; \
			fi; \
		done

test: build ## Run functional tests in all labs that have a Makefile
	@for dir in $(BUILD_DIR)/*/; do \
		lab=$$(basename $$dir); \
		if [ -f "$$lab/Makefile" ]; then \
			$(MAKE) -C $$lab test; \
		fi \
	done

format-check: ## Check formatting without modifying files
	find . -name '*.cpp' -o -name '*.hpp' -o -name '*.h' | \
		grep -v build | xargs clang-format --dry-run --Werror
