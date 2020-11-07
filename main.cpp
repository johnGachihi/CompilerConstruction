#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    fstream mFile("sample.txt");
    mFile << "Hullabaloo";
    mFile.seekg(0);

    int c = mFile.get();

    cout << (c == 'H');

    mFile.close();
}
