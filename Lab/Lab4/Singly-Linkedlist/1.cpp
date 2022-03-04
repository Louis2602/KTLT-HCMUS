#include <iostream>
using namespace std;


struct Node {
    int data;
    Node *next;
};
Node* createNode(Node *&head, int data) {
    Node *tmp = new Node();
    tmp->data = data;
    tmp->next = head;
    head = tmp;
    return head;
}

void printList(Node* head)
{
    while (head != NULL) {
        cout << head->data << " -> ";
        head = head->next;
    }
    cout << "Null\n";
}

int main() {
    Node *head = NULL;
    createNode(head, 3);
    createNode(head, 4);
    createNode(head, 2);
    createNode(head, 5);
    createNode(head, 6);
    createNode(head, 7);
    createNode(head, 11);
    printList(head);
    return 0;
}

