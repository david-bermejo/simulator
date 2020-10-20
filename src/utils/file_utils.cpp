#include "file_utils.h"

#include <fstream>
#include <sstream>

std::vector<unsigned char> readFile(const std::string& path)
{
	std::ifstream file;
	file.open(path, std::ios::in);

	std::stringstream sstream;
	sstream << file.rdbuf();
	const std::string data = sstream.str();
	return std::vector<unsigned char>(data.begin(), data.end());
}