#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int NAME_SIZE = 20;
struct student
{
    float grade;
    char *name;
};
void writeFile(fstream &fs, string fn)
{
    student s;

    fs.open(fn, ios::out | ios::binary);

    if (fs)
    {
        s.name = new char[NAME_SIZE];

        cout << "Name: ";
        cin.getline(s.name, NAME_SIZE);
        cout << "Grade: ";
        cin >> s.grade;
        cin.ignore();

        fs.write(reinterpret_cast<char *>(&s), sizeof(s));

        delete[] s.name;

        fs.close();
    }
    else
    {
        cout << fn << " could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
}
void readFile(fstream &fs, string fn)
{
    student s;

    fs.open(fn, ios::in | ios::binary);
    if (fs)
    {
        fs.read(reinterpret_cast<char *>(&s), sizeof(s));
        while (fs)
        {
            cout << "Name: " << s.name << endl;
            cout << "Grade: " << s.grade << endl;

            fs.read(reinterpret_cast<char *>(&s), sizeof(s));
        }
        fs.close();
    }
    else
    {
        cout << fn << " could not be opened" << endl;
        exit(EXIT_FAILURE);
    }
}
int main()
{
    fstream fs;
    string filename;
    int choice;

    cout << "Enter 1 to write, 2 to read: ";
    cin >> choice;
    cin.ignore();

    cout << "Input the file name to work with: ";
    getline(cin, filename);

    if (choice == 1)
        writeFile(fs, filename);
    else
        readFile(fs, filename);

    return 0;
}