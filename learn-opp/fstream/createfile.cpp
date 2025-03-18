#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main(){
    string myText = "Hello World!\n";

    ifstream MyReadFile("testfile.txt");

    while (getline (MyReadFile, myText)) {
        // Output the text from the file
        cout << myText;
      };

      MyReadFile.close();
}