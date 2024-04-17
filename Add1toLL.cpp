#include <iostream>
using namespace std;
class Node {
  public:
       int data;
       Node* next;
       Node() {
           this->data = 0;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->next = NULL;
       }
       Node (int data, Node* next) {
           this->data = data;
           this->next = next;
       }
};

int helper(Node* temp)
{
    if (temp == NULL)
    {
        return 1;
    }
    int carry = helper(temp->next);

    temp->data = temp->data+carry;
    if (temp->data < 10)
    {
        return 0;
    }
    temp->data = 0;
    return 1;
}

Node* addOne(Node* head)
{
    Node* temp = head;
    int carry = helper(temp);
    if (carry == 1)
    {
        Node* newNode = new Node(1);
        newNode->next = head;
        return newNode;
    }
    return head;

}

int main()
{
    Node* head = new Node(9);
    head->next = new Node(9);
    head->next->next = new Node(9);
    head->next->next->next = new Node(9);
    Node* temp = head;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
    cout << endl;

    head = addOne(head);

    temp = head;

    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }
}
