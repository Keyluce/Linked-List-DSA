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
Node* findIntersection(Node *firstHead, Node *secondHead)
{
    //Write your code here
    if (firstHead == NULL || secondHead == NULL) return NULL;
    Node* temp1 = firstHead;
    Node* temp2 = secondHead;

    while (temp1 != temp2)
    {
        temp1 = temp1->next;
        temp2 = temp2->next;

        if (temp1 == temp2)
        {
            return temp1;
        }
        if (temp1 == NULL)
        {
            temp1 = secondHead;
        }
        if (temp2 == NULL)
        {
            temp2 = firstHead;
        }

    }
    return temp1;
}


int main()
{
    Node* firstHead = new Node(1);
    firstHead->next = new Node(2);
    firstHead->next->next = new Node(9);
    firstHead->next->next->next = new Node(9);
    
    Node* secondHead = new Node(5);
    secondHead->next = new Node(3);
    secondHead->next->next = firstHead->next->next;
    secondHead->next->next->next = firstHead->next->next->next;

    Node* temp = firstHead;
    Node* temp2 = secondHead;

    while (temp != NULL)
    {
        cout << temp -> data << ' ';
        temp = temp->next;
    }
    cout << endl;
    while (temp2!= NULL)
    {
        cout << temp2 -> data << ' ';
        temp2 = temp2->next;
    }

    cout << endl;
    cout << findIntersection(firstHead, secondHead)->data;

}