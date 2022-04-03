#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
Node *addHead(Node *&pHead, int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = pHead;
    pHead = tmp;
    return pHead;
}
void print(Node *head)
{
    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << '\n';
}
void removePos(Node *&pHead, int pos)
{
    if (pHead == NULL)
        return;
    Node *tmp = pHead;
    if (pos == 0)
    {
        pHead = tmp->next;
        delete tmp;
        return;
    }
    for (int i = 0; tmp != NULL && i < pos - 1; i++)
        tmp = tmp->next;
    if (tmp == NULL || tmp->next == NULL)
        return;
    Node *next = tmp->next->next;
    delete tmp->next;
    tmp->next = next;
}
int main()
{
    Node *head = NULL;
    addHead(head, 1);
    addHead(head, 3);
    addHead(head, 2);
    addHead(head, 5);
    addHead(head, 4);
    print(head);
    int pos;
    cout << "Enter a position: ";
    cin >> pos;
    removePos(head, pos);
    print(head);
    return 0;
}
