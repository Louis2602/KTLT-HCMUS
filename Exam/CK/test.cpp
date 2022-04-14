#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Node
{
    string name;
    float area;
    int population;
    Node *next = nullptr;
};
struct City
{
    Node *head = nullptr;
    Node *tail = nullptr;
};

Node *createNode(string name, float area, int population)
{
    Node *p = new Node();
    p->name = name;
    p->area = area;
    p->population = population;
    p->next = nullptr;
    return p;
}
void addTail(City &city, string name, float area, int population)
{
    Node *p = createNode(name, area, population);
    if (city.head == NULL)
    {
        city.head = city.tail = p;
        return;
    }
    city.tail->next = p;
    city.tail = p;
}
City readFile()
{
    fstream fs("Cities.txt", ios::in);
    City city;
    string name;
    float area;
    int population;
    while (!fs.eof())
    {
        getline(fs, name, ',');
        fs >> area;
        fs.ignore();
        fs >> population;
        fs.ignore();
        addTail(city, name, area, population);
    }
    fs.close();
    return city;
}
void printCities(City C)
{
    int i = 0;
    Node *p = C.head;
    while (p)
    {
        cout << ++i << ". " << p->name << '\n';
        p = p->next;
    }
    cout << '\n';
}
void removeCity(City C, int X)
{
    int curr_city;
    Node *p = C.head;
    while (p->next != NULL)
    {
        if (p->population > X)
            curr_city = p->population;
        p = p->next;
    }
    Node *q = C.head;
    while (q->next != NULL)
    {
        if (q->next->population == curr_city)
        {
            Node *t = q->next;
            q->next = t->next;
            delete t;
        }
        q = q->next;
    }
}
int main()
{
    City city;
    city = readFile();
    printCities(city);
    removeCity(city, 1200000);
    printCities(city);
}