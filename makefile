

CC=x86_64-elf-gcc
CXX=x86_64-elf-gxx
AR=x86_64-elf-ar
RANLIB=x86_64-elf-ranlib
LINK=x86_64-elf-ld
STRIP=x86_64-elf-strip
AS=yasm

KERNEL_OBJS=bootstrap.o boot.o

CCFLAGS=-ffreestanding -Wall -Wextra -ansi -pedantic -Werror -m32
LINKFLAGS=-nostdlib -m elf_i386
ASFLAGS=-felf32
CXXFLAGS=$(CCFLAGS) -fno-exceptions -fno-rtti

bootstrap.o : bootstrap.s
	$(AS) bootstrap.s $(ASFLAGS) -o bootstrap.o

boot.o : boot.c
	$(CC) $(CCFLAGS) -c boot.c -o boot.o

kernel : $(KERNEL_OBJS) linker.ld
	$(LINK) $(LINKFLAGS) -T linker.ld -o kadabra.bin $(KERNEL_OBJS) -L./libgcc.a
