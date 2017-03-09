.PHONY: all

all:
	$(MAKE) -f makefile_lib
	$(MAKE) -f makefile_facade
	$(MAKE) -f makefile_test
	@echo "build successful"

.PHONY: clean

clean:
	$(MAKE) -f makefile_facade clean
	$(MAKE) -f makefile_lib clean
	$(MAKE) -f makefile_test clean
	@echo "clean successful"

