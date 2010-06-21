#include <SDL/SDL.h>
#include <stdio.h>

int main(int argc, char **argv)
{
    SDL_Surface *screen;
    SDL_Event event;

    /* init */
    if (0 != SDL_Init(SDL_INIT_VIDEO)) {
        printf("Unable to init SDL: %s\n", SDL_GetError());
        return 1;
    }

    /* SDL_Quit */
    atexit(SDL_Quit);

    /* 256x256 16bit */
    screen = SDL_SetVideoMode(256, 256, 16, 0);
    if (screen == NULL) {
        printf("Unable to set video mode: %s\n", SDL_GetError());
        return 1;
    }

    /* event loop */
    while (0 != SDL_WaitEvent(&event)) {
        switch (event.type) {
            case SDL_MOUSEMOTION:
                printf("Mouse motion. ");
                printf("New position is (%i, %i). ",
                        event.motion.x, event.motion.y);
                printf("That is a (%i, %i) change. \n",
                        event.motion.xrel, event.motion.yrel);
                break;
            case SDL_MOUSEBUTTONDOWN:
                printf("Mouse button pressed. ");
                printf("Button %i at (%i, %i)\n",
                        event.button.button,
                        event.button.x, event.button.y);
                break;
            case SDL_QUIT:
                printf("Quit event. Bye.\n");
                exit(0);
        }
    }

    return 0;
}

