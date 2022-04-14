#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int count1(int n, int m, int max)
{
    if (n == 0)
        return 1;
    if (n < m)
        return 0;
    int sum = 0;
    for (int i = m; i <= max; i++)
        sum += count1(n - i, m, i);
    return sum;
}

struct City
{
    string name;
    float area;
    int population;
};
struct Node
{
    City city;
    Node *next;
    Node *head;
    Node *tail;
};

Node *createNode(City city)
{
    Node *p = new Node();
    p->city = city;
    p->next = NULL;
    return p;
}
Node *readFile(Node *&head, Node *&tail, City city[])
{
    fstream fs("Cities.txt", ios::in);
    int n = 0;
    while (!fs.eof())
    {
        getline(fs, city[n].name, ',');
        fs >> city[n].area;
        fs.ignore();
        fs >> city[n].population;
        fs.ignore();
        n++;
    }
    fs.close();
    Node *p = head;
    if (head == NULL)
        p = head = tail = createNode(city[0]);
    for (int i = 0; i < n; i++)
    {
        Node *tmp = createNode(city[i]);
        p->next = tmp;
        p->city = tmp->city;
        tmp->next = NULL;
        p = p->next;
    }
    tail = p;
    return head;
}
void printCities(Node *C, Node *head, Node *tail)
{
    int i = 0;
    cout << "The first city: ";
    cout << head->city.name << ", " << head->city.area << ", " << head->city.population << '\n';
    cout << "The last city: ";
    cout << tail->city.name << ", " << tail->city.area << ", " << tail->city.population << '\n';
    while (C->next != NULL)
    {
        cout << ++i << ". " << C->city.name << '\n';
        C = C->next;
    }
    cout << '\n';
}
void removeCity(Node *C, int X)
{
    int curr_city;
    Node *p = C;
    while (p->next != NULL)
    {
        if (p->city.population > X)
            curr_city = p->city.population;
        p = p->next;
    }
    cout << curr_city << '\n';
    Node *q = C;
    while (q->next != NULL)
    {
        if (q->next->city.population == curr_city)
        {
            Node *t = q->next;
            q->next = t->next;
            delete t;
        }
        q = q->next;
    }
}
int **createSumMatrix(int A[][4], int n)
{
    int curr_sum = 0;
    int **B = new int *[2];
    for (int i = 0; i < 2; i++)
        B[i] = new int[2];
    int r = 0, c = 0;
    for (int i = 0; i < 2 * n; i += n)
    {
        for (int j = 0; j < 2 * n; j += n)
        {
            curr_sum = 0;
            for (int m = i; m < i + n; m++)
            {
                for (int k = j; k < j + n; k++)
                {
                    curr_sum += A[m][k];
                }
            }
            B[i / n][j / n] = curr_sum;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
            cout << B[i][j] << " ";
        cout << '\n';
    }
    return B;
}

int main()
{
    City city[100];
    Node *head = NULL;
    Node *tail = NULL;
    Node *p;
    p = readFile(head, tail, city);
    printCities(p, head, tail);
    removeCity(p, 1200000);
    printCities(p, head, tail);
    // cout << count1(6, 2, 6);
    // int A[4][4] = {
    //     {1, 2, 3, 4},
    //     {1, 2, 3, 4},
    //     {1, 1, 5, 5},
    //     {1, 1, 5, 5},
    // };
    // createSumMatrix(A, 2);
    return 0;
}