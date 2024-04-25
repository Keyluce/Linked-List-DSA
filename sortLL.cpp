#include <bits/stdc++.h>
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

Node* mergeTwoLists(Node* leftHead, Node* rightHead)
{
    Node* dummyNode = new Node(-1);
    Node* res = dummyNode;
    while (leftHead != NULL && rightHead != NULL)
    {
        if (leftHead -> data <= rightHead->data)
        {
            res->next = leftHead;
            res = leftHead;
            leftHead = leftHead->next;
        }
        else{
            res->next = rightHead;
            res = rightHead;
            rightHead = rightHead->next;
        }
        
    }
    if (leftHead)
    {
        res->next = leftHead;
    }
    else res->next = rightHead;

    return dummyNode->next;
}
Node* findMiddle(Node* head)
{
    Node* slow = head;
    Node* fast = head->next;

    while (fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}
Node* sortList(Node* head){
    
    if (head == NULL || head->next == NULL)
    {
        return head;
    }

    Node* middle = findMiddle(head);
     
    Node* left = head;
    Node* right = middle->next;
    middle->next = NULL;
   
    
    Node* leftHead = sortList(left);
    Node* rightHead = sortList(right);

    return mergeTwoLists(leftHead, rightHead);

}

int main()
{
    Node* firstHead = new Node(1);
    firstHead->next = new Node(2);
    firstHead->next->next = new Node(9);
    firstHead->next->next->next = new Node(7);
    firstHead->next->next->next->next = new Node(4);
    firstHead->next->next->next->next->next = new Node(3);
    

    cout << endl;
    Node* temp = sortList(firstHead);

    while (temp != NULL)
    {
        cout << temp -> data << ' ';
        temp = temp->next;
    }

}