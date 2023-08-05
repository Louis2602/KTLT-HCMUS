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
void removeAll(Node *&pHead)
{
    if (pHead == NULL)
        return;
    Node *tmp = new Node();
    while (pHead != NULL)
    {
        tmp = pHead;
        pHead = pHead->next;
        delete tmp;
    }
    delete pHead;
    cout << "All nodes are deleted successfully.";
}
void print(Node *pHead)
{
    while (pHead != NULL)
    {
        cout << pHead->data << " -> ";
        pHead = pHead->next;
    }
    cout << '\n';
}
int main()
{
    Node *pHead = NULL;
    addHead(pHead, 3);
    addHead(pHead, 5);
    addHead(pHead, 2);
    addHead(pHead, 4);
    addHead(pHead, 1);
    print(pHead);
    removeAll(pHead);
    print(pHead);
    return 0;
}