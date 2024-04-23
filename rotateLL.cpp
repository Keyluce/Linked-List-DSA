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


Node *rotate(Node *head, int k) {

     if (head == NULL) return NULL;
    Node* tail = head;
    int length = 1;
    while (tail->next != NULL)
    {
         length++;
         tail = tail ->next;
    }
    int rotateNumber = k % length;
    if (rotateNumber == 0) return head;
    Node* temp = head;
    int counter = 1;
    while (counter != length - rotateNumber)
    {
         counter++;
          temp = temp->next;
    }
     
     tail->next = head;
     head = temp->next;
     temp->next = NULL;
    return head;
}

int main()
{
    Node* firstHead = new Node(1);
    firstHead->next = new Node(2);
    firstHead->next->next = new Node(9);
    firstHead->next->next->next = new Node(9);
    

  
  
    cout << endl;
    Node* temp = rotate(firstHead,2);

    while (temp != NULL)
    {
        cout << temp -> data << ' ';
        temp = temp->next;
    }

}