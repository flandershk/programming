.PHONY: all
		
all:
	$(MAKE) -f makefile_adapter
	$(MAKE) -f makefile_plugged
	$(MAKE) -f makefile_seabird
	$(MAKE) -f makefile_test
	$(MAKE) -f makefile_two_way_adapter
	@echo "build successful"

.PHONY: clean

clean:
	$(MAKE) -f makefile_adapter clean
	$(MAKE) -f makefile_plugged clean
	$(MAKE) -f makefile_seabird clean
	$(MAKE) -f makefile_test clean
	$(MAKE) -f makefile_two_way_adapter clean
	@echo "clean successful"

