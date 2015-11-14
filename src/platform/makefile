
all: 
	@echo Entering `pwd`/memory
	cd memory && $(MAKE) all && cp libkmemory.a ../..
	@echo Leaving `pwd`/memory

clean:
	cd memory && $(MAKE) clean 
	@echo Cleaning `pwd`...
	rm -f ../libkmemory.a
