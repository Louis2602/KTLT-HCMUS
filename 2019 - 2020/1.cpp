#include <iostream>
#include <cstring>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

struct List
{
    Node *head = NULL;
};

Node *createNode(int data)
{
    Node *p = new Node();
    p->data = data;
    p->next = NULL;
    return p;
}
void addTail(List &ls, int data)
{
    Node *p = createNode(data);
    if (ls.head == NULL)
    {
        ls.head = p;
        return;
    }
    Node *t = ls.head;
    while (t->next != NULL)
        t = t->next;
    t->next = p;
}
void print(List ls)
{
    Node *p = ls.head;
    while (p)
    {
        cout << p->data << " -> ";
        p = p->next;
    }
    cout << '\n';
}
int CountOccurrences(List ls, int num)
{
    if (ls.head == NULL)
        return 0;
    Node *p = ls.head;
    int cnt = 0;
    while (p)
    {
        if (p->data == num)
            cnt++;
        p = p->next;
    }
    return cnt;
}
bool IsPermutation(List ls1, List ls2)
{
    int cnt[100];
    memset(cnt, 0, sizeof(cnt));
    Node *p1 = ls1.head;
    while (p1)
    {
        if (cnt[p1->data] == 0)
            cnt[p1->data] += CountOccurrences(ls1, p1->data);
        p1 = p1->next;
    }
    Node *p2 = ls2.head;
    while (p2)
    {
        cnt[p2->data]--;
        p2 = p2->next;
    }
    for (int i = 0; i < 100; i++)
    {
        if (cnt[i] != 0)
            return false;
    }
    return true;
}
int main()
{
    List ls1, ls2;
    cout << "List 1: ";
    addTail(ls1, 12);
    addTail(ls1, 23);
    addTail(ls1, 2);
    addTail(ls1, 9);
    addTail(ls1, 15);
    addTail(ls1, 23);
    print(ls1);
    cout << "List 2: ";
    addTail(ls2, 2);
    addTail(ls2, 23);
    addTail(ls2, 15);
    addTail(ls2, 12);
    addTail(ls2, 9);
    addTail(ls2, 23);
    print(ls2);
    // cout << CountOccurrences(ls1, 23);
    if (IsPermutation(ls1, ls2))
        cout << "true";
    else
        cout << "false";
    return 0;
}