#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node()
    {
        this->data = 0;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
    Node(int data, Node *next)
    {
        this->data = data;
        this->next = next;
    }
};

Node *reverseLL(Node *head)
{
    Node *temp = head;
    Node *prev = NULL;

    while (temp != NULL)
    {
        Node *var = temp->next;
        temp->next = prev;
        prev = temp;
        temp = var;
    }
    return prev;
}

Node *findKthNode(Node *head, int k)
{
    Node *temp = head;
    k--;
    while (temp != NULL && k > 0)
    {
        k--;
        temp = temp->next;
    }
    return temp;
}
Node *kReverse(Node *head, int k)
{

    Node *temp = head;
    Node *prevNode = NULL;
    while (temp != NULL)
    {
        Node *kthNode = findKthNode(temp, k);

        if (kthNode == NULL)
        {
            if (prevNode)
            {
                prevNode->next = temp;
            }
            break;
        }

        Node *nextNode = kthNode->next;
        kthNode->next = NULL;
        reverseLL(temp);
        if (head == temp)
        {
            head = kthNode;
        }
        else
        {
            prevNode->next = kthNode;
        }
        prevNode = temp;

        temp = nextNode;
    }
    return head;
}

int main()
{
    Node *firstHead = new Node(2);
    firstHead->next = new Node(1);
    firstHead->next->next = new Node(4);
    firstHead->next->next->next = new Node(3);

    cout << endl;
    Node *temp = kReverse(firstHead, 2);

    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}