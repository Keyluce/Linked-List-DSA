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

bool detectCycle(Node *head)
{

    Node* slow = head;
    Node* fast = head;
    while ( fast != NULL && fast->next != NULL )
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
        {
            return true;
        }
        
    }
    return false;
}

int main()
{
    Node* firstHead = new Node(1);
    firstHead->next = new Node(2);
    firstHead->next->next = new Node(9);
    firstHead->next->next->next = new Node(9);
    
    firstHead->next->next->next = firstHead->next->next;

    Node* temp = firstHead;
  
    cout << endl;
    cout << detectCycle(firstHead);

}