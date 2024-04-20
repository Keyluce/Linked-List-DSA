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

Node* removeElements(Node* head, int val) {

        Node* temp = head;
        Node* dummy = new Node(-1);
        dummy->next = head;
        Node* prev = dummy;
        
        while (temp != NULL) {
            if (temp->data == val) {
               
                    Node* remove = temp;
                    prev->next = temp->next;
                    temp = prev->next;
                    delete remove;
                

            } else {
                prev = temp;
                temp = temp->next;
            }
        }
        return dummy->next;
    }

int main()
{
    Node* firstHead = new Node(1);
    firstHead->next = new Node(3);
    firstHead->next->next = new Node(9);
    firstHead->next->next->next = new Node(3);
  
    cout << endl;
    

    removeElements(firstHead, 3);
    Node* temp = firstHead;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }

 
}

