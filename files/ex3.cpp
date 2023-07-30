#include <iostream>
#include <cstdlib>
#include <string>
#include <fstream>
using namespace std;
const int SIZE = 80;
void writeFile(fstream &fs, string filename)
{
    char st[SIZE], ch;

    fs.open(filename, ios::out | ios::binary);

    if (fs)
        while (true)
        {
            cout << "Enter a string: ";
            cin.getline(st, SIZE);

            fs.write(st, sizeof(st));

            cout << "Do you want to continue (Y/N): ";
            cin.get(ch);
            cin.ignore();
            if (ch != 'Y' && ch != 'y')
            {
                fs.close();
                break;
            }
        }
    else
    {
        cout << filename << " could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
}
void appendFile(fstream &fs, string filename)
{
    char st[SIZE], ch;

    cout << "Appending to an existing file" << endl;

    fs.open(filename, ios::out | ios::app | ios::binary);
    if (fs)
        while (true)
        {
            cout << "Enter a string: ";
            cin.getline(st, SIZE);

            fs.write(st, sizeof(st));

            cout << "Do you want to continue (Y/N): ";
            cin >> ch;
            cin.ignore();
            if (ch != 'Y' && ch != 'y')
            {
                fs.close();
                break;
            }
        }
    else
    {
        cout << filename << " could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
}
void readFile(fstream &fs, string filename)
{
    char st[SIZE];

    cout << "Opening a file to read" << endl;

    fs.open(filename, ios::in | ios::binary);
    if (fs)
    {
        fs.read(st, SIZE);
        while (fs)
        {
            cout << st << endl;
            fs.read(st, SIZE);
        }
        fs.close();
    }
    else
    {
        cout << filename << " could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
}
int main()
{
    fstream fs;
    string filename;
    cout << "Input the file name to output: ";
    getline(cin, filename);

    writeFile(fs, filename);

    appendFile(fs, filename);

    readFile(fs, filename);

    return 0;
}