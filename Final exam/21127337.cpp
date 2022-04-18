#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// Cau 1
// a
void printList(int **A, int p, int q)
{
    for (int i = 0; i < p; i++)
    {
        for (int j = 0; j < q; j++)
        {
            cout << A[i][j] << " ";
        }
        cout << '\n';
    }
}
// b
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int **createNewMatrix(int **A, int p, int q)
{
    int n = gcd(p, q);
    int sum = 0;
    int **M = new int *[p / n];
    for (int i = 0; i < n; i++)
        M[i] = new int[n];
    for (int i = 0; i < p - n + 1; i += n)
    {
        for (int j = 0; j < q - n + 1; j += n)
        {
            sum = 0;
            for (int u = i; u < i + n; u++)
            {
                for (int v = j; v < j + n; v++)
                {
                    sum += A[u][v];
                }
            }
            M[i / n][j / n] = sum;
        }
    }
    return M;
}
// Cau 2
int count2(int n, int m)
{
    if (n == 1)
        return 1;
    int cnt = 0;
    for (int i = m; i >= 2; i--)
    {
        if (n % i == 0)
            cnt += count2(n / i, i);
    }
    return cnt;
}
// Cau 3
struct Node
{
    string name;
    int height;
    int weight;
    Node *next;
};
struct People
{
    Node *head = NULL;
    Node *tail = NULL;
};
Node *createNode(string name, int height, int weight)
{
    Node *p = new Node();
    p->name = name;
    p->height = height;
    p->weight = weight;
    p->next = NULL;
    return p;
}
void addTail(People &p, string name, int height, int weight)
{
    Node *t = createNode(name, height, weight);
    if (p.head == NULL)
    {
        p.head = p.tail = t;
        return;
    }
    p.tail->next = t;
    p.tail = t;
}
People readFile()
{
    fstream fs("people.txt", ios::in);
    People p;
    string name;
    int height, weight;
    while (!fs.eof())
    {
        getline(fs, name, '-');
        fs >> height;
        fs.ignore();
        fs >> weight;
        fs.ignore();

        addTail(p, name, height, weight);
    }
    fs.close();
    return p;
}
void printPeople(People P)
{
    Node *t = P.head;
    int i = 0;
    while (t)
    {
        cout << ++i << ". " << t->name << '\n';
        t = t->next;
    }
}
void removePeople(People P, int X)
{
    Node *t = P.head;
    string lastP;
    while (t->next != NULL)
    {
        if (t->height > X)
            lastP = t->name;
        t = t->next;
    }
    Node *q = P.head;
    while (q->next != NULL)
    {
        if (q->next->name == lastP)
        {
            Node *r = q->next;
            q->next = r->next;
            delete r;
        }
        q = q->next;
    }
}
int main()
{
    cout << count2(100, 26);
    return 0;
}
