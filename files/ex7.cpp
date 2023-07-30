#include <iostream>
#include <string>
#include <fstream>
using namespace std;
void displayString(string str)
{
    for (int i = 0; i < str.size(); i++)
        cout << i << "\t";
    cout << endl;
    for (int i = 0; i < str.size(); i++)
        cout << str[i] << "\t";
    cout << endl;
}
int main()
{
    fstream fs;
    string filename = "abc.txt";
    string str = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char ch;
    fs.open(filename, ios::out);

    if (fs)
    {
        fs << str;
        fs.close();
    }
    else
    {
        cout << filename << " could not be opened" << endl;
        return 1;
    }

    fs.open(filename, ios::in);
    if (fs)
    {
        fs.seekg(0L, ios::end);
        long size = fs.tellg();
        cout << "The size of this file is " << size << endl;
        fs.seekg(0L, ios::beg);
        while (true)
        {
            long offset, pos;
            int mode;

            displayString(str);
            pos = fs.tellg();
            cout << "Currently at position " << pos << endl;
            cout << "Enter the offset: ";
            cin >> offset;
            cout << "Enter the mode (0: beg, 1: cur, 2: end, 3 exit): ";
            cin >> mode;

            switch (mode)
            {
            case 0:
                if (offset < 0 || offset >= size)
                    cout << "Out of range" << endl;
                else
                    fs.seekg(offset, ios::beg);
                break;
            case 1:
                if (pos + offset < 0 || pos + offset >= size)
                    cout << "Out of range" << endl;
                else
                    fs.seekg(offset, ios::cur);
                break;
            case 2:
                if (size + offset < 0 || offset >= 0)
                    cout << "Out of range" << endl;
                else
                    fs.seekg(offset, ios::end);
                break;
            default:
                fs.close();
                return 0;
            }
            fs.get(ch);
            if (fs)
                cout << ch;
            else
            {
                fs.clear();
                fs.seekg(0L, ios::beg);
            }
            cout << endl
                 << endl;
        }
    }
    else
    {
        cout << filename << " could not be opened" << endl;
        return 1;
    }

    return 0;
}