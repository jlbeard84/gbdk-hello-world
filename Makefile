all:
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -c -o hello_world.o hello_world.c
	/opt/gbdk/bin/lcc -Wa-l -Wl-m -Wl-j -o hello_world.gb hello_world.o

clean:
	rm -rf *.o *.lst *.map *.gb *~ *.rel *.cdb *.ihx *.lnk *.sym *.asm *.noi