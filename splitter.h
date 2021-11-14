#ifndef SPLITTER_H
#define SPLITTER_H

#include <iostream>
#include <cstring>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;
const static int BUF_SIZE = 1024 * 1024;

void split(string input_file_name){
    ifstream input_file(input_file_name, ios::binary);
    if(!input_file.is_open()){
        cout << "filed to open " << input_file_name << endl;
        exit(EXIT_FAILURE);
    }
    char *buf = new char[BUF_SIZE];

    string output_directory = input_file_name + "_store/";
    auto path = fs::current_path() / output_directory;
    if(fs::exists(path)){
        fs::remove_all(path);
    }
    fs::create_directory(path);

    int i = 0;
    while(input_file.tellg() != -1){
        bzero(buf, BUF_SIZE);
        input_file.read(buf, BUF_SIZE);
        string output_file_name = output_directory + input_file_name + "_" + to_string(i++);
        ofstream output_file(output_file_name, ios::binary);
        output_file.write(buf, BUF_SIZE);
    }

    delete[] buf;
}


#endif
