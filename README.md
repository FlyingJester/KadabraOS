Kadabra
=======

Not KadabraOS or Kadabra OS. Why did I call the repo KadabraOS, then? Because that way you know it is an OS. I guess. Let's move on!

What is Kadabra for?
--------------------

It's just for fun.

How to build Kadabra
--------------------

I do most of my development of Kadabra on OS X and FreeBSD, so these instructions are mostly tailored for OS X and BSD.
The only real differences between OS X, BSD, and Linux for development work is where to get your cross compiler.

Here is where I originally got mine:
https://docs.google.com/file/d/0BxDNp6DGU6SZcmlHVWpNblRnWWs/

I later compiled my own from scratch, but it is nice to get things bootstrapped with a prebuilt toolchain.

If you are comfortable setting up your own cross-compilation environment, don't worry about this next part (skip down to "Compiling").

Setting Up You Environment:
Download this and unpack it into your root as Cross64. This should mean that KadabraOS/Cross64/bin contains x86_64-elf-gcc and related binaries.
Next you will need to symlink libgcc.a to the root folder. The following command works for the prebuilt toolchain:

`ln -s Cross64/lib/gcc/x86_64-elf/4.7.1/libgcc.a ./libgcc.a`

We don't try to go out and find libgcc simply because it's easier and faster to just symlink it like this.

Compiling:
You will need to set some environment variables to match your toolchain. These default to:

CC=x86_64-elf-gcc
CXX=x86_64-elf-gxx
AR=x86_64-elf-ar
RANLIB=x86_64-elf-ranlib
LINK=x86_64-elf-ld
STRIP=x86_64-elf-strip

Run `make kernel` to try and make the kernel.

Testing:
I test in two environments. Using syslinux on floppies or zip disks, and using Qemu. To run in qemu:

`qemu-system-x86_64 -kernel kadabra.bin`

To create a syslinux floppy or zipdisk (BE SURE YOU ACTUALLY KNOW THE NAME OF YOUR DRIVE!):

`syslinux --install /dev/fd0`

Or on Windows:

`syslinux --install a:`

Then, copy from syslinux's root bios/com32/mboot/mboot.c32 and bios/com32/lib/libcom32.c32 to the disk root, and copy syslinux.cfg and kadabra.bin from the Kadabra root to the floppy.

You should then be able to boot from the disk you have prepared.

Can I use Windows to build or test Kadabra?
-------------------------------------------

Do whatever you want to. I don't use Windows for OS development because Windows is not very nice to develop an OS in. Many basic tools, especially relating to preparing files and disks and images, simply do not exist for Windows.
The same can be said of MSVC, which, while legend has it can create freestanding code (the kind needed by a kernel), is a huge pain to actually make a kernel using.

You'd be best served, if you absolutely cannot fathom the idea of using FreeBSD, OpenBSD, or Linux, by installing msys2 or cygwin and compiling Kadabra with that.
But better still would be to just use OS X, BSD, or Linux.
