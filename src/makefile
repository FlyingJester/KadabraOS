
all: kadabra.bin

kernel: kadabra.bin

bootstrap.o : bootstrap.s
	$(XAS) bootstrap.s $(XASFLAGS) -o bootstrap.o

boot.o : boot.c
	$(XCC) $(XCCFLAGS) -c boot.c -o boot.o

kadabra.bin : $(KERNEL_OBJS) linker.ld
	$(XLINK) $(XLINKFLAGS) -T linker.ld -o kadabra.bin $(KERNEL_OBJS) -L./libgcc.a

clean:
	rm *.o 
	rm kadabra.bin
