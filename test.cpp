#include <iostream>
#include <fstream>

using namespace std;

int main(){
    ifstream file("./main.cpp", ios::binary);
    if(!file.is_open()){
        cout << "not open!" << endl;
        exit(EXIT_FAILURE);
    }
    
    while(file.tellg() != -1){
        char ch = file.get();
        if(ch == '\0'){
            cout << "here" << endl;
        } else
            cout << ch;
    }


    return 0;
}

