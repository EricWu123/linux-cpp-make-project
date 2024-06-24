# 顶层 Makefile

SUBDIRS := src tests

export TOP_DIR := $(shell git rev-parse --show-toplevel)
export BUILD_DIR := $(TOP_DIR)/build

.PHONY: all clean test

all:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir; \
	done

clean:
	@for dir in $(SUBDIRS); do \
		$(MAKE) -C $$dir clean; \
	done

test:
	$(MAKE) -C tests
