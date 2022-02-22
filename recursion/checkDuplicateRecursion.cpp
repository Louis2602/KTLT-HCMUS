#include <iostream>

using namespace std;
bool checkDuplicate(int *a, int size)
{
    if (size == 1)
        return true;
    if (checkDuplicate(a, size - 1))
    {
        for (int i = 1; i < size; i++)
        {
            if (a[i] == a[size])
                return false;
        }
    }
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 7, 8, 9, 11};
    int size = sizeof(a) / sizeof(a[0]);
    bool ans = checkDuplicate(a, size);
    ans ? cout << "True" : cout << "False";
    return 0;
}