#include <bits/stdc++.h>
using namespace std;


    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };


Node<int> *sortTwoLists(Node<int> *first, Node<int> *second) {
  Node<int>* dummyNode = new Node<int>(-1);
  Node<int>* res = dummyNode;

  while (first != NULL && second != NULL) {
    if (first->data <= second->data) {
      res->next = first;
      res = first;
      first = first->next;
    } else if (first->data > second->data) {
      res->next = second;
      res = second;
      second = second->next;
    }
  
  }
  while (first)
  {
      res->next = first;
      res = first;
      first = first->next;
  }
  while (second)
  {
      res->next = second;
      res = second;
      second = second->next;
  }
  res->next = NULL;
  return dummyNode->next;
}

int main()
{
  Node<int>* firstHead = new Node(31);
    firstHead->next = new Node(37);
    firstHead->next->next = new Node(46);
    firstHead->next->next->next = new Node(47);
    firstHead->next->next->next->next = new Node(51);
    firstHead->next->next->next->next->next = new Node(62);
    firstHead->next->next->next->next->next->next = new Node(72);
    firstHead->next->next->next->next->next->next->next = new Node(73);
    firstHead->next->next->next->next->next->next->next->next = new Node(90);
    Node<int>* secondHead = new Node(4);
    secondHead->next = new Node(37);
    secondHead->next->next = new Node(45);
    secondHead->next->next->next = new Node(47);
    secondHead->next->next->next->next = new Node(49);
    secondHead->next->next->next->next->next = new Node(50);
    secondHead->next->next->next->next->next->next = new Node(75);
    secondHead->next->next->next->next->next->next->next = new Node(85);
    secondHead->next->next->next->next->next->next->next->next = new Node(86);

  
    cout << endl;
    
    Node<int>* temp = sortTwoLists(firstHead,secondHead);
    

    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }

 
}
