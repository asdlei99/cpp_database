#ifndef CONCACTOR_H
#define CONCACTOR_H
#include <iostream>
#include <string>
#include <fstream>
#include <filesystem>

using namespace std;
namespace fs = std::filesystem;

void concact(const char *filename){

    string directory(filename);
    directory += "_store/";
    auto path = fs::current_path() / directory;
    if(!fs::exists(path)){
        cout << "no file found!" << endl;
    }
    


}


#endif