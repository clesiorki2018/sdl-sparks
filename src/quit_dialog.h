#ifndef QUIT_DIALOG_H
#define QUIT_DIALOG_H

#include "SurfaceClass.hpp"
#include "ButtonClass.hpp"
#include "StringData.hpp"

bool quit_dialog(const ScreenSurface& screen);
bool hand_dialog(const ScreenSurface& screen, const std::string& dialog_text, int size = 28);

#endif

