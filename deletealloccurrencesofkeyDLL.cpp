#include <iostream>
using namespace std;
 class Node {
 public:
       int data;
       Node *prev;
       Node *next;
       Node() {
           this->data = 0;
           this->prev = NULL;
           this->next = NULL;
       }
       Node(int data) {
           this->data = data;
           this->prev = NULL;
           this->next = NULL;
       }
       Node (int data, Node *next, Node *prev) {
          this->data = data;
           this->prev = prev;
           this->next = next;
       }
  };

Node * deleteAllOccurrences(Node* head, int k) {
    
    Node* temp = head;

    while (temp != NULL)
    {
        if (temp->data == k)
        {
            if (temp == head)
            {
                head = head->next;
            }
            Node* nextNode = temp->next;
            Node* prevNode = temp->prev;

            if (nextNode) nextNode->prev = prevNode;
            if (prevNode) prevNode->next = nextNode;


            free (temp);

        }
        temp = temp->next;
    }
    return head;

}


int main()
{
    Node* firstHead = new Node(1);
    firstHead->prev = NULL;
    firstHead->next = new Node(3);
    firstHead->next->prev = firstHead;
    firstHead->next->next = new Node(9);
    firstHead->next->next->prev = firstHead->next;

    firstHead->next->next->next = new Node(3);
    firstHead->next->next->next->prev = firstHead->next->next;
 
  
    cout << endl;
    
    deleteAllOccurrences(firstHead, 3);
    Node* temp = firstHead;
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }

}
