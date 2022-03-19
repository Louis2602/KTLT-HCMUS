#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int row, column = 25;
    cout << "How many words will you enter? ";
    cin >> row;

    char **strArr = 0;
    strArr = new char *[row];
    int i;
    for (i = 0; i < row; i++)
        strArr[i] = new char[column];

    for (i = 0; i < row; i++)
    {
        cout << "Enter word " << i + 1 << ": ";
        cin >> strArr[i];
    }

    for (int i = 0; i < row - 1; i++)
    {
        for (int j = i + 1; j < row; j++)
        {
            if (strcmp(strArr[i], strArr[j]) > 0)
            {
                char tmp[20];
                strcpy(tmp, strArr[i]);
                strcpy(strArr[i], strArr[j]);
                strcpy(strArr[j], tmp);
            }
        }
    }

    cout << strArr[0];

    for (i = 0; i < row; i++)
        delete[] strArr[i];
    delete[] strArr;

    return 0;
}