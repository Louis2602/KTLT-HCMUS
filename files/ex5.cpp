#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int NAME_SIZE = 20, ADDR_SIZE = 20;
struct student
{
    char name[NAME_SIZE];
    char addr[ADDR_SIZE];
    float grade;
};
student inputData()
{
    student s;

    cout << "Creating a structure ..." << endl;
    cout << "Name: ";
    cin.getline(s.name, NAME_SIZE);
    cout << "Address: ";
    cin.getline(s.addr, ADDR_SIZE);
    cout << "Grade: ";
    cin >> s.grade;
    cin.ignore();

    return s;
}
void writeFile(fstream &fs, string filename)
{
    student s;
    char ch;

    fs.open(filename, ios::out | ios::binary);
    if (fs)
        while (true)
        {
            s = inputData();

            fs.write(reinterpret_cast<char *>(&s), sizeof(s));

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
    student s;
    char ch;

    cout << "Appending to an existing file" << endl;

    fs.open(filename, ios::out | ios::app | ios::binary);
    if (fs)
        while (true)
        {
            s = inputData();

            fs.write(reinterpret_cast<char *>(&s), sizeof(s));

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
    student s;

    cout << "Opening a file to read" << endl;

    fs.open(filename, ios::in | ios::binary);
    if (fs)
    {
        fs.read(reinterpret_cast<char *>(&s), sizeof(s));

        while (fs)
        {
            cout << "Name: " << s.name << endl;
            cout << "Address: " << s.addr << endl;
            cout << "Grade: " << s.grade << endl;

            fs.read(reinterpret_cast<char *>(&s), sizeof(s));
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