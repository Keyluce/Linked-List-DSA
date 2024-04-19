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

int lengthOfLoop(Node *head) {

    Node* slow = head;
    Node* fast = head;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast)
        {
            int count = 1;
            fast = fast->next;
            while (fast != slow)
            {
                count = count + 1;
                fast = fast->next;
                
            }
            return count;
        }
    }
    return 0;
}


int main()
{
    Node* firstHead = new Node(1);
    firstHead->next = new Node(2);
    firstHead->next->next = new Node(9);
    firstHead->next->next->next = new Node(9);
    
    firstHead->next->next->next->next = firstHead;

    Node* temp = firstHead;
  
    cout << endl;
    cout << lengthOfLoop(firstHead);

}