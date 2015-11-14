MEMORY_OBJS=platform_mmu.o mmu.o
export PLATFORM_NAME?=i686

all: install_lib

install_lib : library $(MEMORY_OBJS)
	cp libkmemory.a ..

library : $(MEMORY_OBJS)
	$(XAR) rvs libkmemory.a $(MEMORY_OBJS)
	$(XRANLIB) libkmemory.a

platform_mmu.o : $(PLATFORM_NAME)_mmu.c mmu.h
	$(XCC) $(XCCFLAGS) -c $(PLATFORM_NAME)_mmu.c -o platform_mmu.o

mmu.o : mmu.c mmu.h
	$(XCC) $(XCCFLAGS) -c mmu.c -o mmu.o

clean:
	@echo Cleaning `pwd`...
	rm -f *.a
	rm -f *.o
