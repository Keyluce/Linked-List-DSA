#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node *random;
    Node() : data(0), next(nullptr), random(nullptr){};
    Node(int x) : data(x), next(nullptr), random(nullptr) {}
    Node(int x, Node *next, Node *random) : data(x), next(next), random(random) {}
};

void putInBetween(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        Node *newNode = new Node(temp->data);
        newNode->next = temp->next;
        temp->next = newNode;
        temp = temp->next->next;
    }
}
void connectRandom(Node *head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        if (temp->random)
        {
            temp->next->random = temp->random->next;
        }
        else
            temp->next->random = NULL;

        temp = temp->next->next;
    }
}
Node *extractList(Node *head)
{
    Node *dummyNode = new Node(-1);
    Node *res = dummyNode;
    Node *temp = head;

    while (temp != NULL)
    {
        res->next = temp->next;
        res = res->next;

        temp->next = temp->next->next;
        temp = temp->next;
    }
    return dummyNode->next;
}
Node *cloneLL(Node *head)
{
    putInBetween(head);
    connectRandom(head);
    return extractList(head);
}

int main()
{
    Node *firstHead = new Node(1);
    firstHead->next = new Node(3);
    firstHead->next->next = new Node(9);
    firstHead->next->next->next = new Node(3);

    cout << endl;

    firstHead = cloneLL(firstHead);
    Node *temp = firstHead;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}