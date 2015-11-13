export KERNEL_OBJS=bootstrap.o boot.o kstring.o kterm.o kio.o

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

kadabra.bin : $(KERNEL_OBJS) linker.ld
	$(XLINK) $(XLINKFLAGS) -T linker.ld -o kadabra.bin $(KERNEL_OBJS) -L./libgcc.a

clean:
	rm *.o 
	rm kadabra.bin
