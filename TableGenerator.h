/**
 * Project Untitled
*/

#ifndef _TABLEGENERATOR_H
#define _TABLEGENERATOR_H

#include "utils.h"
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using std::string;
using std::vector;
using std::stringstream;
using std::map;
using std::cout;
using std::cin;


class TableGenerator {
public:
    string generateTable(vector<string> headerList, vector<vector<string>> rowList, vector<int> overRiddenHeaderHeight);

    map<int, int> getMaximumWidth(vector<string> headerList, vector<vector<string>> rowList);

    void createRowLines(stringstream& sstr, int headerListSize, map<int, int> columnMaxWidthMapping);

    int getOptimumCellPadding(int cell_index, int data_length, map<int, int> column_max_width_mapping, int cell_padding_size);

    void fillSpace(stringstream& sstr, int length);

    void fillCell(stringstream& sstr, string cell, int cellIndex, map<int, int> columnMaxWidthMapping);

    void printTable(string header, vector<string>result);

private:
    int paddingSize = 1;
    string newLine = "\n";
    string tableJoint = "+";
    string tableVSplit = "|";
    string tableHSplit = "-";
};

#endif  //_TABLEGENERATOR_H