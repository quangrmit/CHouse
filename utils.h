#ifndef _UTILS_H
#define _UTILS_H

#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

std::vector<std::string> split(std::string test, char delimiter);

std::vector<std::string> extractData(std::ifstream &data);

std::string join(std::vector<std::string> list, char joinChar);
#endif
