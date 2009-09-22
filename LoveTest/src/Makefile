#LoveTest Win32 MinGW Makefile

OBJ = ButtonClass.o gb2312_to_Unicode.o main.o MixSoundClass.o QuestionPage.o quit_dialog.o SDL_render_Chinese.o StringData.o SurfaceClass.o UVi_begin.o
LIB = -lmingw32 -lSDLmain -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer -llibintl -liconv -mwindows
NAME = LoveTest.exe

$(NAME): $(OBJ)
	g++ -o $(NAME) $(OBJ) $(LIB)
ButtonClass.o: SurfaceClass.hpp MixSoundClass.hpp ButtonClass.hpp ButtonClass.cpp
	g++ -c ButtonClass.cpp
gb2312_to_Unicode.o: gb2312_to_Unicode.h gb2312_to_Unicode.cpp
	g++ -c gb2312_to_Unicode.cpp
main.o: SurfaceClass.hpp ButtonClass.hpp StringData.hpp QuestionPage.hpp MixSoundClass.hpp quit_dialog.h UVi_begin.h main.h main.cpp
	g++ -c main.cpp
MixSoundClass.o: MixSoundClass.hpp MixSoundClass.cpp
	g++ -c MixSoundClass.cpp
QuestionPage.o: SurfaceClass.hpp ButtonClass.hpp StringData.hpp quit_dialog.h QuestionPage.hpp QuestionPage.cpp
	g++ -c QuestionPage.cpp
quit_dialog.o: SurfaceClass.hpp ButtonClass.hpp StringData.hpp quit_dialog.h quit_dialog.cpp
	g++ -c quit_dialog.cpp
SDL_render_Chinese.o: gb2312_to_Unicode.h SDL_render_Chinese.h SDL_render_Chinese.cpp
	g++ -c SDL_render_Chinese.cpp
StringData.o: StringData.hpp StringData.cpp
	g++ -c StringData.cpp
SurfaceClass.o: SDL_render_Chinese.h SurfaceClass.hpp SurfaceClass.cpp
	g++ -c SurfaceClass.cpp
UVi_begin.o: SurfaceClass.hpp ButtonClass.hpp StringData.hpp QuestionPage.hpp quit_dialog.h UVi_begin.h UVi_begin.cpp
	g++ -c UVi_begin.cpp

