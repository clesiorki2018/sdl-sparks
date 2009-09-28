all:
	g++ -c -o sdl.o -I/opt/local/include -I. sdl.cpp
	g++ -o sdl sdl.o SDLmain.m -F/opt/local/Library/Frameworks -framework SDL -F/System/Library/Frameworks -framework Cocoa

clean:
	rm *.o sdl


