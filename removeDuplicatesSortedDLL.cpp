#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node * removeDuplicates(Node *head)
{
    Node* temp = head;

    while (temp != NULL && temp->next != NULL)
    {
        Node* nextNode = temp->next;

        while (nextNode != NULL && nextNode->data == temp->data)
        {
            Node* remove = nextNode;
            nextNode = nextNode->next;
            free (remove);
        }
        temp->next = nextNode;
        if (nextNode) nextNode -> prev = temp;
        temp = nextNode;
    }
    return head;

}
int main()
{
    Node *firstHead = new Node(1);
    firstHead->prev = NULL;
    firstHead->next = new Node(2);
    firstHead->next->prev = firstHead;
    firstHead->next->next = new Node(2);
    firstHead->next->next->prev = firstHead->next;

    firstHead->next->next->next = new Node(3);
    firstHead->next->next->next->prev = firstHead->next->next;

    cout << endl;

    removeDuplicates(firstHead);

    Node* temp = firstHead;

    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    
}