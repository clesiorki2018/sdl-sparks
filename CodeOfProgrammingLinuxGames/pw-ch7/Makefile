CFLAGS=-W -Wall -ggdb `sdl-config --cflags` -I/usr/include/tcl8.4
LIBS=-lm `sdl-config --libs` -ltcl8.4
OBJS=main.o particle.o background.o resources.o scripting.o network.o
CC=gcc


.PHONY: clean default

default:
	@echo 'Plese check the variables at the top of the Makefile, then run make pw.'

clean:
	rm -f pw $(OBJS)
	rm -f *~

pw: $(OBJS)
	gcc $(CFLAGS) $(OBJS) -o pw $(LIBS)

main.o:	main.c gamedefs.h
	gcc $(CFLAGS) -c main.c

particle.o: particle.c particle.h gamedefs.h
	gcc $(CFLAGS) -c particle.c

background.o: background.c background.h gamedefs.h
	gcc $(CFLAGS) -c background.c

resources.o: resources.c resources.h gamedefs.h
	gcc $(CFLAGS) -c resources.c

scripting.o: scripting.c scripting.h gamedefs.h
	gcc $(CFLAGS) -c scripting.c

network.o: network.c network.h gamedefs.h
	gcc $(CFLAGS) -c network.c
