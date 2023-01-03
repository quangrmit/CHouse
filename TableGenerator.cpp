
#include "utils.h"
#include <iostream>
#include <fstream>
#include <map>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>

using std::cout;
using std::string;
using std::cin;
using std::vector;
using std::stringstream;
using std::map;
using std::unordered_map;
using std::getline;

#define PADDING_SIZE 1 
#define NEW_LINE "n"
#define TABLE_JOINT "+"
#define TABLE_V_SPLsIT "|"
#define TABLE_H_SPLIT "-"

class TableGenerator {
private: 
    int padding_size = 1;
    string new_line = "\n";
    string table_joint = "+";
    string table_v_split = "|";
    string table_h_split = TABLE_H_SPLIT;

public:
    string generater_table(vector<string> header_list, vector<vector<string>> row_list, vector<int> over_ridden_header_height) {
        stringstream sstr;
        int row_height = over_ridden_header_height.size() > 0 ? over_ridden_header_height[0] : 1;
        map<int, int> column_max_width_mapping = get_maximum_width(header_list, row_list);
        sstr << new_line << new_line;

        create_row_lines(sstr, header_list.size(), column_max_width_mapping);
        sstr << new_line;

        for (int header_index = 0; header_index < header_list.size(); header_index++) {
            fill_cell(sstr, header_list[header_index], header_index,column_max_width_mapping);
        }

        sstr << new_line;
        create_row_lines(sstr, header_list.size(), column_max_width_mapping);

        for(vector<string> row : row_list) {

            for (int i = 0; i < row_height; i++) {
                sstr << new_line;
            }

            for (int cell_index = 0; cell_index < row.size(); cell_index++) {
                fill_cell(sstr, row[cell_index], cell_index, column_max_width_mapping);
            }
        }
        
        sstr << new_line;
        
        create_row_lines(sstr, header_list.size(), column_max_width_mapping);
        sstr << new_line;
        sstr << new_line;

        // cout << sstr.str();
        // for (int i =0; i < header_list.size(); i++) {
        //     cout << header_list[i] << "\n";
        // }
        return sstr.str();
    }
    
    map<int, int> get_maximum_width(vector<string> header_list, vector<vector<string>> row_list) {
        map<int, int> column_max_width_mapping = {};

        for (int column_index = 0; column_index < header_list.size(); column_index++) {
            // column_max_width_mapping.insert({column_index, 0});
            column_max_width_mapping[column_index] = 0;
        }

        for (int column_index = 0; column_index < header_list.size(); column_index++) {
            if (header_list[column_index].length() > column_max_width_mapping[column_index]) {
                // column_max_width_mapping.insert({column_index, header_list[column_index].length()});
                column_max_width_mapping[column_index] = header_list[column_index].length();
            }
        }

        for(vector<string> row: row_list) {

            for (int column_index = 0; column_index < row.size(); column_index++) {

                if (row[column_index].length() > column_max_width_mapping[column_index]) {
                    // column_max_width_mapping.insert({column_index, row[column_index].length()});
                    column_max_width_mapping[column_index] = row[column_index].length();
                }
            }
        }

        for (int column_index = 0; column_index < header_list.size(); column_index++) {

            if (column_max_width_mapping[column_index] % 2 !=0) {
                // column_max_width_mapping.insert({column_index,column_max_width_mapping[column_index] + 1});
                column_max_width_mapping[column_index] = column_max_width_mapping[column_index] + 1;
            }
        }

        // for (int i =0; i < column_max_width_mapping.size(); i++) {
        //     cout << column_max_width_mapping[i];            
        // }

        return column_max_width_mapping;
    }

    void create_row_lines(stringstream& sstr, int header_list_size, map<int, int> column_max_width_mapping) {

        for (int i =0; i < header_list_size; i++) {
            if (i==0) {
                sstr << table_joint;
            }
            for (int j = 0; j <column_max_width_mapping[i] + padding_size *2; j++) {
                sstr << table_h_split;                    
            }
            sstr << table_joint;
        }
        // cout << "\nCreate row lines: " <<sstr.str();
    }

    int get_optimum_cell_padding(int cell_index, int data_length, map<int, int> column_max_width_mapping, int cell_padding_size){

        if(data_length % 2 != 0 ) {
            data_length++;
        }

        if (data_length < column_max_width_mapping[cell_index]) {
            cell_padding_size = cell_padding_size + (column_max_width_mapping[cell_index] - data_length) /2;
        }

        return cell_padding_size;
    }

    void fill_space(stringstream& sstr, int length) {
        for (int i =0; i < length; i++) {
            sstr << " ";
        }
    }

    void fill_cell(stringstream& sstr, string cell, int cell_index, map<int, int> column_max_width_mapping) {
        int cell_padding_size = get_optimum_cell_padding(cell_index, cell.length(), column_max_width_mapping, padding_size);

        if(cell_index == 0) {
            sstr << table_v_split;
        }

        fill_space(sstr, cell_padding_size);

        sstr << cell;

        if(cell.length() % 2 != 0 ) {
            sstr << " ";
        }

        fill_space(sstr, cell_padding_size);

        sstr << table_v_split;

        // cout << "\nFill cell:" << sstr.str();
    }

    static void print_table(string file_name, int ID) {
        TableGenerator *table_generator = new TableGenerator();
        vector<string> header_list = {};
        vector <vector<string>> rows_list = {};
        std::fstream my_file;
        my_file.open(file_name, std::ios::in);
        if (!my_file) {
            std::cerr << "Unable to open file \n";
        } else {           
            string header;
            getline(my_file, header);
            header_list = split(header, ',');

            int count = 1;
            string row;
            while (getline(my_file, row)) {
                vector<string> rows = split(row,',');
                if(count == ID) {
                    rows_list.push_back(rows);
                    break;
                } else {
                    count++;
                    continue;
                }
            }
        }

        cout << table_generator->generater_table(header_list, rows_list, {});
        
    }

    // static void print_table(vector<>)

    static void print_table(string file_name) {
        std::fstream my_file;
        my_file.open(file_name, std::ios::in);

        TableGenerator *table_generator  = new TableGenerator();
        vector<string> headers_list = {};
        vector <string> rows_list = {};
    }    
};

int main() {
    vector<string> header = {"ID","Name", "Age", "School"};
    vector<vector<string>> rows = {{"01", "Linh", "20", "RMIT"}, {"02", "Quang", "19", "RMIT"}, {"03", "Phu", "19", "RMIT"}};
    TableGenerator *table_generator = new TableGenerator();
    // stringstream sstr;
    // table_generator->get_maximum_width(header, rows);
    cout << table_generator->generater_table(header,rows,{});
    
    cout << "Hello";
    return 0;
}