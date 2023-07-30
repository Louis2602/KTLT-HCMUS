#include <iostream>
#include <string>
#include <fstream>
using namespace std;
const int NAME_SIZE = 20, ADDR_SIZE = 20;
struct student
{
    char name[NAME_SIZE];
    char addr[ADDR_SIZE];
    float score;
};
void inputData(student &s)
{
    cout << "Creating a structure ..." << endl;
    cout << "Name: ";
    cin.getline(s.name, NAME_SIZE);
    cout << "Address: ";
    cin.getline(s.addr, ADDR_SIZE);
    cout << "Score: ";
    cin >> s.score;
    cin.ignore(); // Skip over the remaining newline
}
void writeFile(fstream &fs, string filename)
{
    char ch;
    student s;

    fs.open(filename, ios::out | ios::binary);
    if (fs)
        while (true)
        {
            inputData(s);

            fs.write(reinterpret_cast<char *>(&s), sizeof(s));
            // fs.write((char *) &s, sizeof(s));

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
        exit(EXIT_FAILURE); // Indicate unsuccessful termination
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
            cout << s.addr << endl;
            cout << s.score << endl;
            cout << endl;

            fs.read(reinterpret_cast<char *>(&s), sizeof(s));
        }
        fs.clear();
        fs.seekg(0L, ios::beg);
        while (fs)
        {
            fs.read(reinterpret_cast<char *>(&s), sizeof(s));
            cout << s.name << endl;
            cout << s.addr << endl;
            cout << s.score << endl;
            cout << endl;
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
    readFile(fs, filename);

    return 0;
}