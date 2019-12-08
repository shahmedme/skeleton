#include <iostream>
#include <string>
using namespace std;

string getFilename(string filepath) {
    int count=0, j;
    string filename;

    for(int i=filepath.length(); i>0; i--) {
        count++;

        if(filepath[i] == '/') {
            count--;
            break;
        }
    }

    for(int i=filepath.length()-count+1, j=0; i<filepath.length(); i++, j++){
        filename[j] = filepath[i];
    }

    return "one";
}
