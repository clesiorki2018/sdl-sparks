#ifndef QUESTION_PAGE_HPP
#define QUESTION_PAGE_HPP

#include <vector>
#include "SurfaceClass.hpp"
#include "ButtonClass.hpp"
#include "StringData.hpp"
#include "quit_dialog.h"

class QuestionPage
{
private:
	std::string questionStrLineOne;
	std::string questionStrLineTwo;
	Button answerButtonA;
	Button answerButtonB;
	Button answerButtonC;
	Button answerButtonD;
	PictureSurface animalLogoA;
	PictureSurface animalLogoB;
	PictureSurface animalLogoC;
	PictureSurface animalLogoD;
	const PictureSurface* pageBG;
	char playerChoice;
public:
	QuestionPage(const std::string& line_one, const std::string& line_two,
		const std::string& answer_a, const std::string& answer_b, const std::string& answer_c, const std::string& answer_d,
		const std::string& animal_a, const std::string& animal_b, const std::string& animal_c, const std::string& animal_d,
		const PictureSurface& bg, const ScreenSurface& screen);
	int display(const ScreenSurface& screen);
	char rtn();
};


//game fonction
void show_loading(int s, const PictureSurface& bg, const ScreenSurface& screen);
void load_pages(std::vector<QuestionPage>& page, const PictureSurface& bg, const ScreenSurface& screen);
bool get_result_quit(std::vector<char>& result, const PictureSurface& bg, const ScreenSurface& screen);


#endif

