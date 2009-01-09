#include "UVi_begin.h"

void UVi_begin(const ScreenSurface& screen)
{
	const int BEGIN_X = 50;
	const int BEGIN_Y = 150;
	screen.fillColor();
	screen.flip();
	
	SDL_Event gameEvent;
	int flashCtrl = 0;
	bool flash = true;
	for ( int i = 0; i < 600; i++){
		while ( SDL_PollEvent(&gameEvent) != 0 ){
			if ( gameEvent.type == SDL_KEYDOWN ){
				return;
			}
			if ( gameEvent.type == SDL_MOUSEBUTTONDOWN ){
				return;
			}
		}
		screen.fillColor();
		int size = 150-i;
		if ( size <= 80 )
			size = 80;
		int x = BEGIN_X+i;
		if ( x >= 150 )
			x = 150;
		int y = BEGIN_Y+i;
		if ( y >= 180 )
			y = 180;
		StringData bText("Common");
		TextSurface UVi_logo("UVi Soft", screen, 215, 195, 122, size);
		TextSurface begin(bText[10], screen, 215, 195, 122);
		UVi_logo.blit(x, y);
		if ( flashCtrl == 0 )
			flash = true;
		if ( flashCtrl == 30 )
			flash = false;
		if ( size == 80 && x == 150 && y == 180 ){
			if ( flash == true ){
				begin.blit(200, 400);
				flashCtrl++;
			}
			else {
				flashCtrl--;
			}
		}
		screen.flip();
	}

	return;
}

bool title_loop_quit(const ScreenSurface& screen)
{
	SDL_Event gameEvent;
	StringData myText("Common");

	PictureSurface bg("./images/h3_bg.png", screen);
	TextSurface gameTitle(myText[6], screen, 215, 195, 122, 50);
	TextSurface copyright(myText[7], screen, 215, 195, 122);

	const int centre_x = (screen.point()->w) / 2;
	const int title_x = centre_x - (gameTitle.point()->w / 2);
	const int title_y = 150;
	const int copyright_x = centre_x - (copyright.point()->w /2);
	const int copyright_y = 420;
	const int button_x = centre_x - (120/2);
	const int button_y = 300;
	const int version_x = 20;
	const int version_y = 20;
	
	
	Button beginButton("./images/begin_button_off.png", "./images/begin_button_over.png", screen);
	beginButton.setup(button_x, button_y, 5);
	TextSurface beginTextOff(myText[8], screen, 185, 165, 97);
	TextSurface beginTextOver(myText[8], screen, 215, 195, 122);
	beginButton.addText(beginTextOff, beginTextOver);
	TextSurface version("Version 1.04.1", screen, 215, 195, 122, 20);
	//version.toSolid();
	
	bg.blit(0);
	gameTitle.blit(title_x, title_y);
	copyright.blit(copyright_x,copyright_y);
	beginButton.blitOut();
	version.blit(version_x, version_y);
	screen.flip();
	while( true ){
		while ( SDL_PollEvent(&gameEvent) != 0 ){
			if ( gameEvent.type == SDL_QUIT ){
				if ( quit_dialog(screen) == true ){
					return true;
				}
			}
			if ( gameEvent.type == SDL_KEYDOWN ){
				if ( gameEvent.key.keysym.sym == SDLK_ESCAPE ){
					if ( quit_dialog(screen) == true ){
						return true;
					}
				}
			}

			//beginButton.getEvent(gameEvent);
			bg.blit(0);
			gameTitle.blit(title_x, title_y);
			copyright.blit(copyright_x,copyright_y);
			version.blit(version_x, version_y);
			if ( beginButton.effectiveClick(gameEvent) == true )
				return false;
			screen.flip();
		}
		SDL_Delay(10);
	}
}

bool show_result_quit(const std::vector<char>& result, const ScreenSurface& screen)
{
	//there are 8 questions and 8 answers.

	StringData aText("Result");
	const int SIZE = 18;
	std::vector<TextSurface> answers;

	//1;
	answers.push_back(TextSurface (aText[0], screen, 200, 200, 200, SIZE));
	if ( result[0] == 'a' ){
		answers.push_back(TextSurface(aText[1], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[2], screen, 215, 195, 122, SIZE));
	}
	else if ( result[0] == 'b' ){
		answers.push_back(TextSurface(aText[3], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[4], screen, 215, 195, 122, SIZE));
	}
	else if ( result[0] == 'c' ){
		answers.push_back(TextSurface(aText[5], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[6], screen, 215, 195, 122, SIZE));
	}
	else if ( result[0] == 'd' ){
		answers.push_back(TextSurface(aText[7], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[8], screen, 215, 195, 122, SIZE));
	}

	//2
	answers.push_back(TextSurface (aText[9], screen, 200, 200, 200, SIZE));
	if ( result[1] == 'a' ){
		answers.push_back(TextSurface(aText[10], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[11], screen, 215, 195, 122, SIZE));
	}
	else if ( result[1] == 'b' ){
		answers.push_back(TextSurface(aText[12], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[13], screen, 215, 195, 122, SIZE));
	}
	else if ( result[1] == 'c' ){
		answers.push_back(TextSurface(aText[14], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[15], screen, 215, 195, 122, SIZE));
	}
	else if ( result[1] == 'd' ){
		answers.push_back(TextSurface(aText[16], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[17], screen, 215, 195, 122, SIZE));
	}

	//3
	answers.push_back(TextSurface (aText[18], screen, 200, 200, 200, SIZE));
	if ( result[2] == 'a' ){
		answers.push_back(TextSurface(aText[19], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[20], screen, 215, 195, 122, SIZE));
	}
	else if ( result[2] == 'b' ){
		answers.push_back(TextSurface(aText[21], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[22], screen, 215, 195, 122, SIZE));
	}
	else if ( result[2] == 'c' ){
		answers.push_back(TextSurface(aText[23], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[24], screen, 215, 195, 122, SIZE));
	}
	else if ( result[2] == 'd' ){
		answers.push_back(TextSurface(aText[25], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[26], screen, 215, 195, 122, SIZE));
	}

	//4
	answers.push_back(TextSurface (aText[27], screen, 200, 200, 200, SIZE));
	if ( result[3] == 'a' ){
		answers.push_back(TextSurface(aText[28], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[29], screen, 215, 195, 122, SIZE));
	}
	else if ( result[3] == 'b' ){
		answers.push_back(TextSurface(aText[30], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[31], screen, 215, 195, 122, SIZE));
	}
	else if ( result[3] == 'c' ){
		answers.push_back(TextSurface(aText[32], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[33], screen, 215, 195, 122, SIZE));
	}
	else if ( result[3] == 'd' ){
		answers.push_back(TextSurface(aText[34], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[35], screen, 215, 195, 122, SIZE));
	}

	//5
	answers.push_back(TextSurface(aText[36], screen, 200, 200, 200, SIZE));
	if ( result[4] == 'a' ){
		answers.push_back(TextSurface(aText[37], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[38], screen, 215, 195, 122, SIZE));
	}
	else if ( result[4] == 'b' ){
		answers.push_back(TextSurface(aText[39], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[40], screen, 215, 195, 122, SIZE));
	}
	else if ( result[4] == 'c' ){
		answers.push_back(TextSurface(aText[41], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[42], screen, 215, 195, 122, SIZE));
	}
	else if ( result[4] == 'd' ){
		answers.push_back(TextSurface(aText[43], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[44], screen, 215, 195, 122, SIZE));
	}

	//6
	answers.push_back(TextSurface(aText[45], screen, 200, 200, 200, SIZE));
	if ( result[5] == 'a' ){
		answers.push_back(TextSurface(aText[46], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[47], screen, 215, 195, 122, SIZE));
	}
	else if ( result[5] == 'b' ){
		answers.push_back(TextSurface(aText[48], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[49], screen, 215, 195, 122, SIZE));
	}
	else if ( result[5] == 'c' ){
		answers.push_back(TextSurface(aText[50], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[51], screen, 215, 195, 122, SIZE));
	}
	else if ( result[5] == 'd' ){
		answers.push_back(TextSurface(aText[52], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[53], screen, 215, 195, 122, SIZE));
	}

	//7
	answers.push_back(TextSurface(aText[54], screen, 200, 200, 200, SIZE));
	if ( result[6] == 'a' ){
		answers.push_back(TextSurface(aText[55], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[56], screen, 215, 195, 122, SIZE));
	}
	else if ( result[6] == 'b' ){
		answers.push_back(TextSurface(aText[57], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[58], screen, 215, 195, 122, SIZE));
	}
	else if ( result[6] == 'c' ){
		answers.push_back(TextSurface(aText[59], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[60], screen, 215, 195, 122, SIZE));
	}
	else if ( result[6] == 'd' ){
		answers.push_back(TextSurface(aText[61], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[62], screen, 215, 195, 122, SIZE));
	}

	//8
	answers.push_back(TextSurface(aText[63], screen, 200, 200, 200, SIZE));
	if ( result[7] == 'a' ){
		answers.push_back(TextSurface(aText[64], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[65], screen, 215, 195, 122, SIZE));
	}
	else if ( result[7] == 'b' ){
		answers.push_back(TextSurface(aText[66], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[67], screen, 215, 195, 122, SIZE));
	}
	else if ( result[7] == 'c' ){
		answers.push_back(TextSurface(aText[68], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[69], screen, 215, 195, 122, SIZE));
	}
	else if ( result[7] == 'd' ){
		answers.push_back(TextSurface(aText[70], screen, 215, 195, 122, SIZE));
		answers.push_back(TextSurface(aText[71], screen, 215, 195, 122, SIZE));
	}

	//
	PictureSurface resultBG("./images/h3_bg.png", screen);
	const int X = 30;
	const int DELTA = 16;
	const int LINE_NUM = 24;
	int y[LINE_NUM];
	for ( int i = 0; i < LINE_NUM; i++ )
		y[i] = 20 + (DELTA * i);

	resultBG.blit(0);
	for ( int i = 0; i < LINE_NUM; i++ ){
		answers[i].blit(X, y[i]);
	}

	screen.flip();

	const int LB_X = 160 - 60;
	const int RB_X = 160*3 - 60;
	const int B_Y = 410;
	Button restartButton("./images/begin_button_off.png", "./images/begin_button_over.png", screen);
	Button endButton("./images/begin_button_off.png", "./images/begin_button_over.png", screen);
	restartButton.setup(LB_X, B_Y, 5);
	endButton.setup(RB_X, B_Y, 5);
	TextSurface re_off(aText[72], screen, 185, 165, 92);
	TextSurface re_over(aText[72], screen, 215, 195, 122);
	TextSurface end_off(aText[73], screen, 185, 165, 92);
	TextSurface end_over(aText[73], screen, 215, 195, 122);
	restartButton.addText(re_off, re_over);
	endButton.addText(end_off, end_over);
	restartButton.blitOut();
	endButton.blitOut();
	screen.flip();
	
	SDL_Event gameEvent;
	while ( true ){
		while ( SDL_PollEvent(&gameEvent) != 0 ){
			if ( gameEvent.type == SDL_QUIT ){
				return true;
			}
			if ( gameEvent.type == SDL_KEYDOWN ){
                if ( gameEvent.key.keysym.sym == SDLK_ESCAPE ){
					return true;
                }
            }
			resultBG.blit(10, 410, 10, 410, 620, 70);
			if ( restartButton.effectiveClick(gameEvent) == true ){
				return false;
			}
			if ( endButton.effectiveClick(gameEvent) == true ){
				return true;
			}
			screen.flip();
		}
		SDL_Delay(10);
	}
}

void end_show(const ScreenSurface& screen)
{
	StringData endText("End");
	PictureSurface endBG("./images/h3_bg.png", screen);
	TextSurface line0(endText[0], screen, 215, 195, 122, 40);
	TextSurface line1(endText[1], screen, 215, 195, 122);
	TextSurface line2(endText[2], screen, 215, 195, 122);
	TextSurface line3(endText[3], screen, 215, 195, 122);
	TextSurface line4(endText[4], screen, 215, 195, 122);
	TextSurface line5(endText[5], screen, 215, 195, 122);
	TextSurface line6(endText[6], screen, 215, 195, 122);

	endBG.blit(0);
	line0.blit(50,50);
	line1.blit(50,100);
	line2.blit(50,140);
	line3.blit(50,180);
	line4.blit(50,220);
	line5.blit(50,260);
	line6.blit(50,300);
	screen.flip();

	SDL_Event gameEvent;
	for ( int i = 0; i < 505; i++ ){
		while ( SDL_PollEvent(&gameEvent) != 0 ){
			if ( gameEvent.type == SDL_QUIT ){
				return;
			}
			if ( gameEvent.type == SDL_KEYDOWN ){
				return;
			}
			if ( gameEvent.type == SDL_MOUSEBUTTONDOWN ){
				return;
			}
		}
		show_loading(i/5, endBG, screen);
	}

	return;
}


