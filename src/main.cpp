//UVi Soft ( 2008 )
//Long Fei ( lf426 ), E-mail: zbln426@163.com
//Laboratory of ZaiBieLiunNian
//http://www.cppblog.com/lf426/

#include "main.h"

int game(int argc, char* argv[]);
int main(int argc ,char* argv[])
{
	int mainRtn = 0;
	try {
		mainRtn = game(argc, argv);
	}
	catch ( const ErrorInfo& info ) {
		info.show();
		return -1;
	}
	
	return mainRtn;
}

int game(int argc, char* argv[])
{
	//StringData loading...
	StringData myText("Common");

	//Create a SDL screen.
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	const Uint32 SCREEN_FLAGS = 0; //SDL_FULLSCREEN | SDL_DOUBLEBUF | SDL_HWSURFACE
	const std::string WINDOW_NAME = "The Keys To Your Heart";
	ScreenSurface screen(SCREEN_WIDTH, SCREEN_HEIGHT, WINDOW_NAME, 0, SCREEN_FLAGS);

	//bg loading
	PictureSurface bg("./images/h3_bg.png", screen);

	//music loading
	//MusicSound mus("./sounds/bgMusic.mid");
	//mus.play();

	//UVi Logo
	UVi_begin(screen);

	//main loop
	bool gameOver = false;
	while ( gameOver == false ){
		//Title loop
		gameOver = title_loop_quit(screen);
		
		//pages show and get result
		std::vector<char> result;
		if ( gameOver != true ){
			gameOver = get_result_quit(result, bg, screen);
		}
		
		//show result;
		if ( gameOver != true ){
			gameOver = show_result_quit(result, screen);
		}
	}

	//end show
	end_show(screen);

	//end music
	//mus.stop();

	return 0;
}

