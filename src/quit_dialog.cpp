#include "quit_dialog.h"

bool quit_dialog(const ScreenSurface& screen)
{
	const int CENTRE_X = (screen.point()->w) / 2;
	const int CENTRE_Y = (screen.point()->h) / 2;
	const int HALF_SUB_BUTTON_W = 64 / 2;

	PictureSurface quitBG("./images/quitbg.png", screen);
	quitBG.blit();

	StringData myString("Common");
	TextSurface quitDlg(myString[2], screen, 215, 195, 122);
	int quitDlg_x = CENTRE_X - ((quitDlg.point()->w)/2);
	int quitDlg_y = CENTRE_Y - 50;
	quitDlg.blit(quitDlg_x, quitDlg_y);

	const int YES_X = CENTRE_X - 40 - HALF_SUB_BUTTON_W;
	const int YES_Y = CENTRE_Y + 30;
	Button yesButtonEffect("./images/h3_yes_off.png", "./images/h3_yes_over.png", screen);
	yesButtonEffect.setup(YES_X, YES_Y, 5);
	yesButtonEffect.blitOut();

	const int NO_X = CENTRE_X + 40 - HALF_SUB_BUTTON_W;
	const int NO_Y = CENTRE_Y + 30;
	Button noButtonEffect("./images/h3_no_off.png", "./images/h3_no_over.png", screen);
	noButtonEffect.setup(NO_X, NO_Y, 5);
	noButtonEffect.blitOut();

	screen.flip();

	SDL_Event gameEvent;
	while( true ){
        while ( SDL_PollEvent(&gameEvent) != 0 ){
            if ( gameEvent.type == SDL_KEYDOWN ){
                if ( gameEvent.key.keysym.sym == SDLK_ESCAPE ){
					return false;
                }
            }
			quitBG.blit();
			quitDlg.blit(quitDlg_x, quitDlg_y);
			if ( yesButtonEffect.effectiveClick(gameEvent) == true )
				return true;
			if ( noButtonEffect.effectiveClick(gameEvent) == true )
				return false;
			screen.flip();
		}
		SDL_Delay(10);
	}
}

bool hand_dialog(const ScreenSurface& screen, const std::string& dialog_text, int size)
{
	const int CENTRE_X = (screen.point()->w) / 2;
	const int CENTRE_Y = (screen.point()->h) / 2;
	const int HALF_SUB_BUTTON_W = 64 / 2;

	PictureSurface quitBG("./images/dialog_bg.png", screen);
	quitBG.blit();

	TextSurface quitDlg(dialog_text, screen, 215, 195, 122, size);
	int quitDlg_x = CENTRE_X - ((quitDlg.point()->w)/2);
	int quitDlg_y = CENTRE_Y - 50;
	quitDlg.blit(quitDlg_x, quitDlg_y);

	const int YES_X = CENTRE_X - 40 - HALF_SUB_BUTTON_W;
	const int YES_Y = CENTRE_Y + 30;
	Button yesButtonEffect("./images/h3_yes_off.png", "./images/h3_yes_over.png", screen);
	yesButtonEffect.setup(YES_X, YES_Y, 5);
	yesButtonEffect.blitOut();

	const int NO_X = CENTRE_X + 40 - HALF_SUB_BUTTON_W;
	const int NO_Y = CENTRE_Y + 30;
	Button noButtonEffect("./images/h3_no_off.png", "./images/h3_no_over.png", screen);
	noButtonEffect.setup(NO_X, NO_Y, 5);
	noButtonEffect.blitOut();

	screen.flip();

	SDL_Event gameEvent;
	while( true ){
        while ( SDL_PollEvent(&gameEvent) != 0 ){
            if ( gameEvent.type == SDL_KEYDOWN ){
                if ( gameEvent.key.keysym.sym == SDLK_ESCAPE ){
					return false;
                }
            }
			quitBG.blit();
			quitDlg.blit(quitDlg_x, quitDlg_y);
			if ( yesButtonEffect.effectiveClick(gameEvent) == true )
				return true;
			if ( noButtonEffect.effectiveClick(gameEvent) == true )
				return false;
			screen.flip();
		}
		SDL_Delay(10);
	}
}

