g++ -c ButtonClass.cpp
g++ -c main.cpp
g++ -c MixSoundClass.cpp
g++ -c QuestionPage.cpp
g++ -c quit_dialog.cpp
g++ -c StringData.cpp
g++ -c SurfaceClass.cpp
g++ -c UVi_begin.cpp
g++ -o LoveTest ButtonClass.o main.o MixSoundClass.o QuestionPage.o quit_dialog.o StringData.o SurfaceClass.o UVi_begin.o -lSDL -lSDL_image -lSDL_ttf -lSDL_mixer
mv LoveTest ..
