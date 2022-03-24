#include <iostream>
#include <fstream>
#include <string>

using namespace std;
struct People
{
    string name;
    float height;
    float weight;
};

int readFile(char *input, People p[])
{
    fstream fs(input, ios::in);
    int i = 0;
    while (!fs.eof())
    {
        getline(fs, p[i].name, '-');
        fs >> p[i].height;
        fs.ignore();
        fs >> p[i].weight;
        fs.ignore();
        i++;
    }
    fs.close();
    return i;
}
void printPeople(char *input, People p[])
{
    int n = readFile(input, p);
    for (int i = 0; i < n; i++)
    {
        cout << p[i].height / 100 << " " << p[i].name << " " << p[i].weight << endl;
    }
}
void sortPeople(char *input, People p[])
{
    int n = readFile(input, p);
    string lastName[100];
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (p[j].height > p[i].height)
                swap(p[j], p[i]);

    // find last name
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        for (int j = 0; j < p[i].name.size(); j++)
        {
            if (p[i].name[j] != ' ')
                cnt++;
            else
                break;
        }
        lastName[i] = p[i].name.substr(0, cnt - 1);
    }
    for (int i = 0; i < 13; i++)
        cout << lastName[i] << " ";
    cout << '\n';
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (p[j].height == p[i].height)
                if (lastName[j] > lastName[i])
                    swap(p[j], p[i]);
        }
    }
}

void print(char *input, People p[])
{
    for (int i = 0; i < 13; i++)
    {
        cout << p[i].height / 100 << " " << p[i].name << " " << p[i].weight << " " << endl;
    }
}
void calculateWeight(char *input, People p[], int *&less, int *&more, int &l, int &m)
{
    int n = readFile(input, p);
    less = new int[n];
    more = new int[n];
    for (int i = 0; i < n; i++)
    {
        if (p[i].weight > 90)
            more[m++] = p[i].weight;
        else if (p[i].weight < 60)
            less[l++] = p[i].weight;
    }
}
int main()
{
    People p[100];
    char input[] = "people.txt";
    // printPeople(input, p);
    int *less, *more, l = 0, m = 0;
    sortPeople(input, p);
    print(input, p);
    calculateWeight(input, p, less, more, l, m);
    for (int i = 0; i < l; i++)
        cout << less[i] << " ";
    cout << endl;
    for (int i = 0; i < m; i++)
        cout << more[i] << " ";
    delete[] less;
    delete[] more;
    return 0;
}