//UVi Soft ( 2008 )
//Long Fei ( lf426 ), E-mail: zbln426@163.com
//Laboratory of ZaiBieLiunNian
//http://www.cppblog.com/lf426/

//FileName: SDL_render_Chinese.h
//For Windows only

#ifndef RENDER_CHINESE_H
#define RENDER_CHINESE_H

#include "gb2312_to_Unicode.h"
#include "SDL/SDL_ttf.h"

SDL_Surface* myTTF_RenderString_Blended(TTF_Font* font, const std::string& str, SDL_Color fg);
SDL_Surface* myTTF_RenderString_Solid(TTF_Font* font, const std::string& str, SDL_Color fg);
SDL_Surface* myTTF_RenderString_Shaded(TTF_Font* font, const std::string& str, SDL_Color fg, SDL_Color bg);

#endif

