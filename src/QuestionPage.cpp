#include "QuestionPage.hpp"

QuestionPage::QuestionPage(const std::string& line_one, const std::string& line_two,
		const std::string& answer_a, const std::string& answer_b, const std::string& answer_c, const std::string& answer_d,
		const std::string& animal_a, const std::string& animal_b, const std::string& animal_c, const std::string& animal_d,
		const PictureSurface& bg, const ScreenSurface& screen):
questionStrLineOne(line_one), questionStrLineTwo(line_two),
answerButtonA(answer_a, screen,185, 165, 92, 215, 195, 122),
answerButtonB(answer_b, screen,185, 165, 92, 215, 195, 122),
answerButtonC(answer_c, screen,185, 165, 92, 215, 195, 122),
answerButtonD(answer_d, screen,185, 165, 92, 215, 195, 122),
animalLogoA(animal_a, screen),
animalLogoB(animal_b, screen),
animalLogoC(animal_c, screen),
animalLogoD(animal_d, screen),
pageBG(&bg), playerChoice('a')
{}

int QuestionPage::display(const ScreenSurface& screen)
{
	pageBG->blit(0);
	screen.flip();

	const int LINE1_X = 30;
	const int LINE1_Y = 60;
	const int LINE2_X = 30;
	const int LINE2_Y = 90;
	const int ANSWER_A_X = 80;
	const int ANSWER_A_Y = 150;
	const int ANSWER_B_X = 80;
	const int ANSWER_B_Y = 200;
	const int ANSWER_C_X = 80;
	const int ANSWER_C_Y = 250;
	const int ANSWER_D_X = 80;
	const int ANSWER_D_Y = 300;
	const int LOGO_X = 450;
	const int LOGO_Y = 150;
	const int LEFT_X = 400;
	const int LEFT_Y = 400;
	const int RIGHT_X = 500;
	const int RIGHT_Y = 400;
	const int INF_X = 420;
	const int INF_Y = 320;
	const int CHOICE_X = 50;

	TextSurface line1(questionStrLineOne, screen, 215, 195, 122, 20);
	line1.blit(LINE1_X, LINE1_Y);
	TextSurface line2(questionStrLineTwo, screen, 215, 195, 122, 20);
	line2.blit(LINE2_X, LINE2_Y);
	answerButtonA.setup(ANSWER_A_X, ANSWER_A_Y, 5);
	answerButtonA.blitOut();
	answerButtonB.setup(ANSWER_B_X, ANSWER_B_Y, 5);
	answerButtonB.blitOut();
	answerButtonC.setup(ANSWER_C_X, ANSWER_C_Y, 5);
	answerButtonC.blitOut();
	answerButtonD.setup(ANSWER_D_X, ANSWER_D_Y, 5);
	answerButtonD.blitOut();
	animalLogoA.colorKey();
	animalLogoB.colorKey();
	animalLogoC.colorKey();
	animalLogoD.colorKey();
	Button left("./images/h3_pre_off.png", "./images/h3_pre_over.png", screen);
	left.setup(LEFT_X, LEFT_Y, 5);
	left.blitOut();
	Button right("./images/h3_next_off.png", "./images/h3_next_over.png", screen);
	right.setup(RIGHT_X, RIGHT_Y, 5);
	right.blitOut();
	StringData inf("Common");
	TextSurface leftInf(inf[4], screen, 215, 195, 122);
	TextSurface rightInf(inf[3], screen, 215, 195, 122);
	PictureSurface choiceLogo("./images/choice.bmp", screen);
	choiceLogo.colorKey(0xFF, 0xFF, 0xFF);
	if ( playerChoice == 'a' )
		choiceLogo.blit(CHOICE_X, ANSWER_A_Y);
	else if ( playerChoice == 'b' )
		choiceLogo.blit(CHOICE_X, ANSWER_B_Y);
	else if ( playerChoice == 'c' )
		choiceLogo.blit(CHOICE_X, ANSWER_C_Y);
	else if ( playerChoice == 'd' )
		choiceLogo.blit(CHOICE_X, ANSWER_D_Y);
	screen.flip();

	SDL_Event gameEvent;
    while( true ){
		while ( SDL_PollEvent(&gameEvent) != 0 ){
			if ( gameEvent.type == SDL_QUIT ){
				if ( quit_dialog(screen) == true ){
					return 0;
				}
			}
			if ( gameEvent.type == SDL_KEYDOWN ){
				if ( gameEvent.key.keysym.sym == SDLK_ESCAPE ){
					if ( quit_dialog(screen) == true ){
						return 0;
					}
				}
				if ( gameEvent.key.keysym.sym == SDLK_LEFT ){
					return -1;
				}
				if ( gameEvent.key.keysym.sym == SDLK_RIGHT ){
					return 1;
				}
				if ( gameEvent.key.keysym.sym == SDLK_UP ){
					playerChoice--;
					if ( playerChoice <= 'a'){
						playerChoice = 'a';
					}
				}
				if ( gameEvent.key.keysym.sym == SDLK_DOWN ){
					playerChoice++;
					if ( playerChoice >= 'd'){
						playerChoice = 'd';
					}
				}
			}

			pageBG->blit(0);
			line1.blit(LINE1_X, LINE1_Y);
			line2.blit(LINE2_X, LINE2_Y);

			if ( answerButtonA.mouseOver(gameEvent) == true ){
				animalLogoA.blit(LOGO_X, LOGO_Y);
			}
			if ( answerButtonB.mouseOver(gameEvent) == true ){
				animalLogoB.blit(LOGO_X, LOGO_Y);
			}
			if ( answerButtonC.mouseOver(gameEvent) == true ){
				animalLogoC.blit(LOGO_X, LOGO_Y);
			}
			if ( answerButtonD.mouseOver(gameEvent) == true ){
				animalLogoD.blit(LOGO_X, LOGO_Y);
			}

			if ( left.mouseOver(gameEvent) == true ){
				leftInf.blit(INF_X, INF_Y);
			}
			if ( right.mouseOver(gameEvent) == true ){
				rightInf.blit(INF_X, INF_Y);
			}

			if ( answerButtonA.effectiveClick(gameEvent) == true ){
				playerChoice = 'a';
				pageBG->blit(LOGO_X, LOGO_Y, LOGO_X, LOGO_Y, 70, 90, 5, 5);
				animalLogoA.blit(LOGO_X, LOGO_Y);
			}
			if ( answerButtonB.effectiveClick(gameEvent) == true ){
				playerChoice = 'b';
				pageBG->blit(LOGO_X, LOGO_Y, LOGO_X, LOGO_Y, 70, 90, 5, 5);
				animalLogoB.blit(LOGO_X, LOGO_Y);
			}
			if ( answerButtonC.effectiveClick(gameEvent) == true ){
				playerChoice = 'c';
				pageBG->blit(LOGO_X, LOGO_Y, LOGO_X, LOGO_Y, 70, 90, 5, 5);
				animalLogoC.blit(LOGO_X, LOGO_Y);
			}
			if ( answerButtonD.effectiveClick(gameEvent) == true ){
				playerChoice = 'd';
				pageBG->blit(LOGO_X, LOGO_Y, LOGO_X, LOGO_Y, 70, 90, 5, 5);
				animalLogoD.blit(LOGO_X, LOGO_Y);
			}

			if ( playerChoice == 'a' )
				choiceLogo.blit(CHOICE_X, ANSWER_A_Y);
			else if ( playerChoice == 'b' )
				choiceLogo.blit(CHOICE_X, ANSWER_B_Y);
			else if ( playerChoice == 'c' )
				choiceLogo.blit(CHOICE_X, ANSWER_C_Y);
			else if ( playerChoice == 'd' )
				choiceLogo.blit(CHOICE_X, ANSWER_D_Y);

			if ( left.effectiveClick(gameEvent) == true ){
				return -1;
			}
			if ( right.effectiveClick(gameEvent) == true ){
				return 1;
			}

			screen.flip();
		}
		SDL_Delay(10);
	}
}

char QuestionPage::rtn()
{
	return playerChoice;
}


void show_loading(int s, const PictureSurface& bg, const ScreenSurface& screen)
{
	bg.blit(10, 400, 10, 400, 630, 70);
	PictureSurface loadingBG("./images/loading_bg.png", screen);
	loadingBG.colorKey();
	PictureSurface loadingIMG("./images/loading_img.png", screen);

	const int X = 120;
	const int Y = 400;
	int v = 390*s/100;

	loadingIMG.blit(X+5, Y+5, 0, 0, v, 30);
	loadingBG.blit(X, Y);
	screen.flip();
}


void load_pages(std::vector<QuestionPage>& page, const PictureSurface& bg, const ScreenSurface& screen)
{
	StringData myText("GameData");

	PictureSurface loading("./images/loading.png", screen);
	TextSurface loadingText(myText[57], screen, 215, 195, 122);
	loadingText.blit(loading);
	loading.blit();
	screen.flip();
	
	//0
	page.push_back(QuestionPage(myText[9], myText[10], myText[11], myText[12], myText[13], myText[14],
		"./images/anm/Sheep.png", "./images/anm/Rabbit.png", "./images/anm/Deer.png", "./images/anm/Horse.png",
		bg, screen));
	show_loading(100/8, bg, screen);
	//1
	page.push_back(QuestionPage(myText[15], myText[16], myText[17], myText[18], myText[19], myText[20],
		"./images/anm/Lion.png", "./images/anm/Monkey.png", "./images/anm/Snake.png", "./images/anm/Giraffe.png",
		bg, screen));
	show_loading(100/8*2, bg, screen);
	//2
	page.push_back(QuestionPage(myText[21], myText[22], myText[23], myText[24], myText[25], myText[26],
		"./images/anm/Cat.png", "./images/anm/Dog.png", "./images/anm/Horse.png", "./images/anm/Snake.png",
		bg, screen));
	show_loading(100/8*3, bg, screen);
	//3
	page.push_back(QuestionPage(myText[27], myText[28], myText[29], myText[30], myText[31], myText[32],
		"./images/anm/Snake.png", "./images/anm/Lion.png", "./images/anm/Crocodile.png", "./images/anm/Shark.png",
		bg, screen));
	show_loading(100/8*4, bg, screen);
	//4
	page.push_back(QuestionPage(myText[33], myText[34], myText[35], myText[36], myText[37], myText[38],
		"./images/anm/Horse.png", "./images/anm/Sheep.png", "./images/anm/Rabbit.png", "./images/anm/Bird.png",
		bg, screen));
	show_loading(100/8*5, bg, screen);
	//5
	page.push_back(QuestionPage(myText[39], myText[40], myText[41], myText[42], myText[43], myText[44],
		"./images/anm/Pig.png", "./images/anm/Dog.png", "./images/anm/Cow.png", "./images/anm/Bird.png",
		bg, screen));
	show_loading(100/8*6, bg, screen);
	//6
	page.push_back(QuestionPage(myText[45], myText[46], myText[47], myText[48], myText[49], myText[50],
		"./images/anm/WhiteTiger.png", "./images/anm/Dinosaur.png", "./images/anm/PolarBear.png", "./images/anm/Leopard.png",
		bg, screen));
	show_loading(100/8*7, bg, screen);
	//7
	page.push_back(QuestionPage(myText[51], myText[52], myText[53], myText[54], myText[55], myText[56],
		"./images/anm/Cat.png", "./images/anm/Lion.png", "./images/anm/Horse.png", "./images/anm/Pigeon.png",
		bg, screen));
	show_loading(100, bg, screen);
}


bool get_result_quit(std::vector<char>& result, const PictureSurface& bg, const ScreenSurface& screen)
{
	//pages loading...
	std::vector<QuestionPage> page;
	load_pages(page, bg, screen);
	StringData myText("Common");
	
	//game begin
	std::vector<QuestionPage>::iterator pPage = page.begin();
	while ( pPage != page.end() ){
		int temp = (*pPage).display(screen);
		if ( temp == 0 ){
			result.push_back('z');
			return true;
		}
		else if ( temp == -1 ){
			if ( pPage != page.begin() ){
				pPage--;
			}
		}
		else if ( temp == 1 ){
			pPage++;
			if ( pPage == page.end() ){
				if ( hand_dialog(screen, myText[9]) != true ){
					pPage--;
				}
			}
		}
	}
	
	//get result
	for ( std::vector<QuestionPage>::iterator pPage = page.begin(); pPage != page.end(); pPage++ ){
			result.push_back((*pPage).rtn());
	}

	return false;
}


