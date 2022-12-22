#ifndef _UTILS_H
#define _UTILS_H

#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <iostream>

std::vector<std::string> split(std::string test, char delimiter);

std::vector<std::string> extractData(std::ifstream &data);

#endif