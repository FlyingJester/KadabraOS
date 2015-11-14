export KERNEL_OBJS=bootstrap.o boot.o kstring.o kterm.o kio.o
export KERNEL_LIBS=libkmemory.a

all: kadabra.bin

kernel: kadabra.bin

bootstrap.o : bootstrap.s
	$(XAS) bootstrap.s $(XASFLAGS) -o bootstrap.o

boot.o : boot.c
	$(XCC) $(XCCFLAGS) -c boot.c -o boot.o

kstring.o : kstring.c
	$(XCC) $(XCCFLAGS) -c kstring.c -o kstring.o

kio.o : kio.c
	$(XCC) $(XCCFLAGS) -c kio.c -o kio.o

kterm.o : kterm.c
	$(XCC) $(XCCFLAGS) -c kterm.c -o kterm.o

libkmemory.a :
	@echo Entering `pwd`/platform
	cd platform && $(MAKE) all
	@echo Leaving `pwd`/platform

kadabra.bin : $(KERNEL_OBJS) $(KERNEL_LIBS) linker.ld
	$(XLINK) $(XLINKFLAGS) -T linker.ld -o kadabra.bin $(KERNEL_OBJS) $(KERNEL_LIBS) -L./libgcc.a

clean:
	cd platform && $(MAKE) clean
	@echo Cleaning `pwd`...
	rm -f *.o 
	rm -f $(KERNEL_LIBS) 
	rm -f kadabra.bin
