#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int NAME_SIZE = 20;
struct student
{
    char name[NAME_SIZE];
    float score;
};
void writeFile(fstream &fs, string filename)
{
    char ch;
    student s;

    cout << "Opening a file to write" << endl;
    fs.open(filename, ios::out | ios::binary);

    if (fs)
        while (true)
        {
            cout << "Creating a structure ..." << endl;
            cout << "Name: ";
            cin.getline(s.name, NAME_SIZE);
            cout << "score: ";
            cin >> s.score;
            cin.ignore();

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
            cout << s.name << endl;
            cout << s.score << endl;
            cout << endl;

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
void updateFile(fstream &fs, string filename)
{
    student s;
    unsigned long numOfItems, item;

    cout << "Opening a file to update" << endl;
    fs.open(filename, ios::in | ios::out | ios::binary);

    fs.seekg(0L, ios::end);
    numOfItems = fs.tellg() / sizeof(student);

    cout << "Which item do you want to update (0 - " << numOfItems - 1 << "): ";
    cin >> item;

    fs.seekg(item * sizeof(student), ios::beg);
    fs.read(reinterpret_cast<char *>(&s), sizeof(student));

    s.score += 1; // Making changes to data

    fs.seekg(item * sizeof(student), ios::beg);
    fs.write(reinterpret_cast<char *>(&s), sizeof(student));

    fs.close();
}
int main()
{
    fstream fs;
    string filename;
    cout << "Input the file name: ";
    getline(cin, filename);

    writeFile(fs, filename);
    readFile(fs, filename);

    updateFile(fs, filename);
    readFile(fs, filename);

    return 0;
}
