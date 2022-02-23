#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    char c[100];
    cin >> c;
    int n = strlen(c);
    int i = 0, j = n - 1;
    bool isPalindrome = true;
    while (i < j)
    {
        if (c[i] != c[j])
        {
            isPalindrome = false;
            break;
        }
        else
        {
            i++;
            j--;
        }
    }
    isPalindrome ? cout << "Palindrome" : cout << "Not a palindrome";
    return 0;
}