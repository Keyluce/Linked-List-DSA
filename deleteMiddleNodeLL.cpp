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

Node* deleteMiddle(Node* head){

    if (head == NULL || head -> next == NULL)
    {
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    
    while (fast->next->next != NULL && fast->next->next->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node* temp = slow->next;
    slow->next = slow->next->next;

    return head;
    
    
}
int main()
{
    Node* firstHead = new Node(1);
    firstHead->next = new Node(2);
    firstHead->next->next = new Node(9);
    firstHead->next->next->next = new Node(3);
    firstHead->next->next->next->next = new Node(4);
  
    cout << endl;
    
    deleteMiddle(firstHead);

    Node* temp = firstHead;
    while (temp != NULL)
    {
        cout << temp -> data << ' ';
        temp = temp->next;
    }

}