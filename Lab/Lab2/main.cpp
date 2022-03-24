#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Players
{
    string role;
    string name;
    int year;
    string country;
    string club;
};
int ReadFile(char *input, Players players[])
{
    ifstream in;
    in.open(input);

    int i = 0;
    while (!in.eof())
    {
        getline(in, players[i].role, '/');
        getline(in, players[i].name, '/');
        in >> players[i].year;
        in.get(); // skip / after year
        getline(in, players[i].country, '/');
        getline(in, players[i].club, '\n');
        i++;
    }
    in.close();
    return i;
}
void findPlayersBornIn1994(char *input, Players players[])
{
    int n = ReadFile(input, players);
    cout << "All players were born in 1994:\n";
    for (int i = 0; i < n; i++)
    {
        if (players[i].year == 1994)
            cout << players[i].name << '\n';
    }
}

void findManchesterUnitedPlayers(char *input, Players players[])
{
    int n = ReadFile(input, players);
    cout << "All players that played for Manchester United:\n";
    for (int i = 0; i < n; i++)
    {
        if (players[i].club == "Manchester United")
            cout << players[i].name << '\n';
    }
}
void findAllFW_ManchesterCity(char *input, Players players[])
{
    int n = ReadFile(input, players);
    cout << "All FW players that played for Manchester City:\n";
    for (int i = 0; i < n; i++)
    {
        if (players[i].role == "FW" && players[i].club == "Manchester City")
            cout << players[i].name << '\n';
    }
}
void swap(string &a, string &b)
{
    string tmp = a;
    a = b;
    b = tmp;
}
void sortPlayers(char *input, Players players[])
{
    int n = ReadFile(input, players);
    string lastName[81];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < players[i].name.size(); j++)
        {
            if (players[i].name[j] == ' ')
            {
                lastName[i] = players[i].name.substr(j, players[i].name.size() - 1);
                break;
            }
        }
    }
    for (int i = 0; i < 80; i++)
        for (int j = i + 1; j < 81; j++)
            if (players[j].year >= players[i].year)
                swap(players[i], players[j]);

    for (int i = 0; i < 80; i++)
        for (int j = i + 1; j < 81; j++)
            if (players[j].year == players[i].year)
                if (lastName[j] < lastName[i])
                    swap(players[i], players[j]);
    for (int i = 0; i < 81; i++)
        cout << i + 1 << "/" << players[i].name << "/" << players[i].year << '\n';
}
int main()
{
    Players players[100];
    char input[] = "Players.txt";
    findPlayersBornIn1994(input, players);
    // findManchesterUnitedPlayers(input, players);
    // findAllFW_ManchesterCity(input, players);
    // sortPlayers(input, players);
    return 0;
}