#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};
void addTail(Node *&pHead, int data)
{
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = NULL;

    if (pHead == NULL)
    {
        pHead = tmp;
        return;
    }
    Node *last = pHead;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = tmp;
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
int main()
{
    Node *head = NULL;
    int n, node;
    cout << "Enter number of nodes: ";
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << "Enter a node: ";
        cin >> node;
        addTail(head, node);
        print(head);
    }
    return 0;
}