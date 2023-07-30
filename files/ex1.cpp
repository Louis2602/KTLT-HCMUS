#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>
using namespace std;
const int M = 10;
const int N = 10;
void inputData(int a[][N], int &m, int &n)
{
    cout << "Enter the number of rows: ";
    cin >> m;
    cout << "Enter the number of columns: ";
    cin >> n;
    cin.ignore();

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            a[i][j] = rand() % 10;
}
void ofsANDifs(int a[][N], int m, int n)
{
    string filename;

    ifstream ifs;
    cout << "Enter the filename to read: ";
    getline(cin, filename);

    ifs.open(filename);
    if (ifs)
    {
        ifs >> m;
        ifs >> n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                ifs >> a[i][j];
        ifs.close();

        int minVal, maxVal;
        minVal = maxVal = a[0][0];
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] < minVal)
                    minVal = a[i][j];
                else if (a[i][j] > maxVal)
                    maxVal = a[i][j];

        cout << "Enter the filename to write: ";
        getline(cin, filename);

        ofstream ofs(filename, ios::app);
        if (ofs)
        {
            ofs << "Minimum value is " << minVal << endl;
            ofs << "Maximum value is " << maxVal << endl;

            ofs.close();
        }
        else
            cout << "Error opening the file" << endl;
    }
    else
        cout << "Error opening the file" << endl;
}
void fs(int a[][N], int m, int n)
{
    fstream fs;
    string filename;
    cout << "Enter the filename to write: ";
    getline(cin, filename);

    fs.open(filename, ios::out);
    if (fs)
    {
        fs << m << endl;
        fs << n << endl;
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
                fs << a[i][j] << " ";
            fs << endl;
        }
        fs.close();
    }
    else
    {
        cout << "Error opening the file" << endl;
        return;
    }

    cout << "Enter the filename to read: ";
    getline(cin, filename);

    fs.open(filename, ios::in);
    if (!fs)
    {
        cout << "Error opening the file" << endl;
        return;
    }

    fs >> m;
    fs >> n;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            fs >> a[i][j];
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    fs.close();
}
int main(int argc, const char *argv[])
{
    srand((int)time(0));

    int a[M][N], m, n;

    inputData(a, m, n);

    fs(a, m, n);

    ofsANDifs(a, m, n);

    return 0;
}