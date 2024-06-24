SUBDIRS := libfoo app 

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
