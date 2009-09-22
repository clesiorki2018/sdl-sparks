#ifndef STRING_DATA_HPP
#define STRING_DATA_HPP

#include <clocale>
#include <string>
#include <vector>
#include <libintl.h>

class StringData
{
private:
	std::vector<std::string> data;
public:
	StringData(const std::string& type);
	std::string operator [](const unsigned int& n) const;
};

#endif

