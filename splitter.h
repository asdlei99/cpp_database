#ifndef SPLITTER_H
#define SPLITTER_H

#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void split(const char *filename){
    string input_file_name = filename;
    ifstream input_file(input_file_name, ios::binary);
    if(!input_file.is_open()){
        cout << "filed to open " << input_file_name << endl;
        exit(EXIT_FAILURE);
    }

    int buf_size = 1024 * 1024;
    char *buf = new char[buf_size];
    string output_directory = input_file_name + "_store/";

    auto path = fs::current_path() / output_directory;
    if(fs::exists(path)){
        fs::remove_all(path);
    }
    fs::create_directory(path);

    int i = 0;
    while(input_file.tellg() != -1){
        bzero(buf, buf_size);
        input_file.read(buf, buf_size);
        string output_file_name = output_directory + input_file_name + "_" + to_string(i++) + ".txt";
        ofstream output_file(output_file_name, ios::binary);
        output_file.write(buf, buf_size);
    }

    delete[] buf;
}


#endif