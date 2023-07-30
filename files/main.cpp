#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream fs("abc.txt", ios::in);
    fs.seekg(0, ios::beg);
    long numBytes = fs.tellg();
    cout << "Num bytes: " << numBytes << endl;
    return 0;
}