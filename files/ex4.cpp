#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
using namespace std;
const int SIZE = 5;
void writeFile(fstream &fs, string filename, int &k)
{
    int n, *p;
    char ch;
    fs.open(filename, ios::out | ios::binary);
    if (fs)
        while (true)
        {
            n = rand() % SIZE + 1;
            p = new int[n];
            cout << "Creating an array ...";
            for (int i = 0; i < n; i++)
                p[i] = k++;
            fs.write(reinterpret_cast<char *>(&n), sizeof(n));
            fs.write(reinterpret_cast<char *>(p), n * sizeof(int));
            delete[] p;
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
void appendFile(fstream &fs, string filename, int &k)
{
    int n, *p;
    char ch;
    cout << "Appending to an existing file" << endl;
    fs.open(filename, ios::out | ios::app | ios::binary);
    if (fs)
        while (true)
        {
            n = rand() % SIZE + 1;
            p = new int[n];
            cout << "Creating an array ...";
            for (int i = 0; i < n; i++)
                p[i] = k++;
            fs.write(reinterpret_cast<char *>(&n), sizeof(n));
            fs.write(reinterpret_cast<char *>(p), n * sizeof(int));
            delete[] p;
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
    int n, *p;

    cout << "Opening a file to read" << endl;

    fs.open(filename, ios::in | ios::binary);
    if (fs)
    {
        while (true)
        {
            fs.read(reinterpret_cast<char *>(&n), sizeof(n));
            if (!fs)
                break;
            p = new int[n];
            fs.read(reinterpret_cast<char *>(p), n * sizeof(int));
            for (int i = 0; i < n; i++)
                cout << p[i] << "\t";
            cout << endl;
            delete[] p;
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
    srand((int)time(0));

    fstream fs;
    string filename;
    int k = 0;
    cout << "Input the file name to output: ";
    getline(cin, filename);

    writeFile(fs, filename, k);

    appendFile(fs, filename, k);

    readFile(fs, filename);

    return 0;
}