/**
 * Project Untitled
 */

#include "TableGenerator.h"

/**
 * TableGenerator implementation
 */

/**
 * @param  {vector<string>} headerList          : 
 * @param  {vector<vector<string>>} rowList     : 
 * @param  {vector<int>} overRiddenHeaderHeight : 
 * @return {string}                             : 
 */
string TableGenerator::generateTable(vector<string> headerList, vector<vector<string>> rowList, vector<int> overRiddenHeaderHeight) {
    stringstream sstr;
    int rowHeight = overRiddenHeaderHeight.size() > 0 ? overRiddenHeaderHeight[0] : 1;
    map<int, int> columnMaxWidthMapping = getMaximumWidth(headerList, rowList);
    sstr << newLine << newLine;

    createRowLines(sstr, headerList.size(), columnMaxWidthMapping);
    sstr << newLine;

    for (int headerIndex = 0; headerIndex < headerList.size(); headerIndex++) {
        fillCell(sstr, headerList[headerIndex], headerIndex,columnMaxWidthMapping);
    }

    sstr << newLine;
    createRowLines(sstr, headerList.size(), columnMaxWidthMapping);

    for(vector<string> row : rowList) {

        for (int i = 0; i < rowHeight; i++) {
            sstr << newLine;
        }

        for (int cellIndex = 0; cellIndex < row.size(); cellIndex++) {
            fillCell(sstr, row[cellIndex], cellIndex, columnMaxWidthMapping);
        }
    }
    
    sstr << newLine;
    
    createRowLines(sstr, headerList.size(), columnMaxWidthMapping);
    sstr << newLine;
    sstr << newLine;

    // cout << sstr.str();
    // for (int i =0; i < header_list.size(); i++) {
    //     cout << header_list[i] << "\n";
    // }
    return sstr.str();
}

/**
 * @param  {vector<string>} headerList      : 
 * @param  {vector<vector<string>>} rowList : 
 * @return {map<int,}                       : 
 */
map<int, int> TableGenerator::getMaximumWidth(vector<string> headerList, vector<vector<string>> rowList) {
    map<int, int> columnMaxWidthMapping = {};

    for (int columnIndex = 0; columnIndex < headerList.size(); columnIndex++) {
        // column_max_width_mapping.insert({column_index, 0});
        columnMaxWidthMapping[columnIndex] = 0;
    }

    for (int columnIndex = 0; columnIndex < headerList.size(); columnIndex++) {
        if (headerList[columnIndex].length() > columnMaxWidthMapping[columnIndex]) {
            // column_max_width_mapping.insert({column_index, header_list[column_index].length()});
            columnMaxWidthMapping[columnIndex] = headerList[columnIndex].length();
        }
    }

    for(vector<string> row: rowList) {

        for (int columnIndex = 0; columnIndex < row.size(); columnIndex++) {

            if (row[columnIndex].length() > columnMaxWidthMapping[columnIndex]) {
                // column_max_width_mapping.insert({column_index, row[column_index].length()});
                columnMaxWidthMapping[columnIndex] = row[columnIndex].length();
            }
        }
    }

    for (int columnIndex = 0; columnIndex < headerList.size(); columnIndex++) {

        if (columnMaxWidthMapping[columnIndex] % 2 !=0) {
            // column_max_width_mapping.insert({column_index,column_max_width_mapping[column_index] + 1});
            columnMaxWidthMapping[columnIndex] = columnMaxWidthMapping[columnIndex] + 1;
        }
    }

    // for (int i =0; i < column_max_width_mapping.size(); i++) {
    //     cout << column_max_width_mapping[i];            
    // }

    return columnMaxWidthMapping;
}

/**
 * @param  {stringstream} sstr          : 
 * @param  {int} headerListSize         : 
 * @param  {map<int} undefined          : 
 * @param  {int>} columnMaxWidthMapping : 
 */
void TableGenerator:: createRowLines(stringstream& sstr, int headerListSize, map<int, int> columnMaxWidthMapping) {

    for (int i =0; i < headerListSize; i++) {
        if (i==0) {
            sstr << tableJoint;
        }
        for (int j = 0; j <columnMaxWidthMapping[i] + paddingSize *2; j++) {
            sstr << tableHSplit;                    
        }
        sstr << tableJoint;
    }
    // cout << "\nCreate row lines: " <<sstr.str();
}

/**
 * @param  {int} cellIndex              : 
 * @param  {int} dataLength             : 
 * @param  {map<int} undefined          : 
 * @param  {int>} columnMaxWidthMapping : 
 * @param  {int} cellPaddingSize        : 
 * @return {int}                        : 
 */
int TableGenerator::getOptimumCellPadding(int cellIndex, int dataLength, map<int, int> columnMaxWidthMapping, int cellPaddingSize){

    if(dataLength % 2 != 0 ) {
        dataLength++;
    }

    if (dataLength < columnMaxWidthMapping[cellIndex]) {
        cellPaddingSize = cellPaddingSize + (columnMaxWidthMapping[cellIndex] - dataLength) /2;
    }

    return cellPaddingSize;
}
/** 
 * @param  {stringstream} sstr : 
 * @param  {int} length        : 
 */

void TableGenerator::fillSpace(stringstream& sstr, int length) {
    for (int i =0; i < length; i++) {
        sstr << " ";
    }
}

/**
 * @param  {stringstream} sstr          : 
 * @param  {string} cell                : 
 * @param  {int} cellIndex              : 
 * @param  {map<int} undefined          : 
 * @param  {int>} columnMaxWidthMapping : 
 */
void TableGenerator::fillCell(stringstream& sstr, string cell, int cellIndex, map<int, int> columnMaxWidthMapping) {
    int cellPaddingSize = getOptimumCellPadding(cellIndex, cell.length(), columnMaxWidthMapping, paddingSize);

    if(cellIndex == 0) {
        sstr << tableVSplit;
    }

    fillSpace(sstr, cellPaddingSize);

    sstr << cell;

    if(cell.length() % 2 != 0 ) {
        sstr << " ";
    }

    fillSpace(sstr, cellPaddingSize);

    sstr << tableVSplit;

    // cout << "\nFill cell:" << sstr.str();
}
/**
 * 
 * @param  {string} header                  : 
 * @param  {vector<string>result} undefined : 
 */
void printTable(string header, vector<string>result) {
    TableGenerator *table_generator  = new TableGenerator();
    vector<string> headersList = split(header, ',');
    vector <vector<string>> rowsList = {};
    for (int i =0; i < result.size(); i++) {
        rowsList.push_back(split(result[i], ','));
    }
    cout << table_generator->generateTable(headersList, rowsList, {});
}