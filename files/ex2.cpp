#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void writeFile(fstream &fs, string filename)
{
    string st;
    char ch;

    fs.open(filename, ios::out);

    if (fs)
        while (true)
        {
            cout << "Enter a string: ";
            getline(cin, st);

            fs << st << endl;

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
    string st;
    char ch;

    cout << "Appending to an existing file" << endl;

    fs.open(filename, ios::out | ios::app);
    if (fs)
        while (true)
        {
            cout << "Enter a string: ";
            getline(cin, st);

            fs << st << endl;

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
    string st;

    fs.open(filename, ios::in);
    if (fs)
    {
        getline(fs, st);
        while (fs)
        {
            cout << st << endl;
            getline(fs, st);
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