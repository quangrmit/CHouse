#include "utils.h"

std::vector<std::string> split(std::string test, char delimiter) {
    std::stringstream ss;
    ss << test;
    std::string segment;
    std::vector<std::string> seglist;

    while (std::getline(ss, segment, delimiter)) {
        seglist.push_back(segment);
    }
    return seglist;
}
std::string join(std::vector<std::string> list, char joinChar) {
    std::string result = list[0];
    for (int i = 1; i < list.size(); i++) {
        std::string s(1, joinChar);
        result.append(s);
        result.append(list[i]);
    }
    return result;
}

std::vector<std::string> extractData(std::ifstream& data) {
    std::vector<std::string> result;
    std::string mid;
    while (true) {
        std::getline(data, mid);
        if (mid.empty()) {
            return result;
        }
        result.push_back(mid);
    }
