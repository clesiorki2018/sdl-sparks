#ifndef UVI_BEGIN_H
#define UVI_BEGIN_H

#include "SurfaceClass.hpp"
#include "ButtonClass.hpp"
#include "StringData.hpp"
#include "QuestionPage.hpp"
#include "quit_dialog.h"

void UVi_begin(const ScreenSurface& screen);
bool title_loop_quit(const ScreenSurface& screen);
bool show_result_quit(const std::vector<char>& result, const ScreenSurface& screen);
void end_show(const ScreenSurface& screen);

#endif

