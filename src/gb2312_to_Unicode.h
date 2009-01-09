//UVi Soft ( 2008 )
//Long Fei ( lf426 ), E-mail: zbln426@163.com
//Laboratory of ZaiBieLiunNian
//http://www.cppblog.com/lf426/

//FileName: gb2312_to_Unicode.h
//For Windows only

#ifndef GB2312_TO_UNICODE_H_
#define GB2312_TO_UNICODE_H_

#include <iostream>
#include <vector>
#include <iconv.h>

//if not include "SDL/SDL.h"
#ifndef _SDL_H
typedef unsigned short int Uint16;
#endif

bool getUnicode(const std::string& str, std::vector<Uint16>& unicodeVectorArray);

#endif

