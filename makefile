

export XCC=x86_64-elf-gcc
export XCXX=x86_64-elf-gxx
export XAR=x86_64-elf-ar
export XRANLIB=x86_64-elf-ranlib
export XLINK=x86_64-elf-ld
export XSTRIP=x86_64-elf-strip
export XAS=yasm

export XCCFLAGS=-ffreestanding -Wall -Wextra -ansi -pedantic -Werror -m32
export XLINKFLAGS=-nostdlib -m elf_i386
export XASFLAGS=-felf32
export XCXXFLAGS=$(XCCFLAGS) -fno-exceptions -fno-rtti

all:
	@echo Entering `pwd`/src
	cd src && $(MAKE) all && cp kadabra.bin ..
	@echo Leaving `pwd`/src

clean:
	cd src && $(MAKE) clean
	@echo Cleaning `pwd`...
	rm -f kadabra.bin
