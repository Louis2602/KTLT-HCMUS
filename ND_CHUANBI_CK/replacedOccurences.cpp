#include <iostream>
#include <cstring>
using namespace std;

char *replaceStr(char *src, char *sub, char *rep);

int main()
{
    char string[] = "brown fox and brown dog";
    char *result = replaceStr(string, "brown", "red");
    cout << string << '\n'
         << result;

    delete result;

    return 0;
}

char *replaceStr(char *src, char *sub, char *rep)
{
    int old_length = strlen(sub);
    int new_length = strlen(rep);
    int src_length = strlen(src);

    char *after;
    if (old_length == new_length)
        after = new char[src_length + 1];
    else
    {
        int occurrences = 0;

        int i = 0;
        while (i < src_length)
        {
            if (strstr(&src[i], sub) == &src[i])
            {
                occurrences++;
                i += old_length;
            }
            else
                i++;
        }
        int sub_diff = new_length - old_length;

        int after_length = src_length;

        after_length += occurrences * sub_diff;
        after = new char[after_length + 1];
    }
    int i = 0;
    int j = 0;
    while (i < strlen(src))
    {
        if (strstr(&src[i], sub) == &src[i])
        {
            strcpy(&after[j], rep);
            i += old_length;
            j += new_length;
        }
        else
        {
            after[j] = src[i];
            i++;
            j++;
        }
    }
    after[j] = '\0';
    return after;
}