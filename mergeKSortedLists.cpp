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


Node* mergeKLists(vector<Node*> &listArray)
   {
   priority_queue<pair<int,Node*>,vector<pair<int,Node*>>,greater<pair<int,Node*>>> pq;

   for (int i = 0; i < listArray.size(); i++)
   {
       if (listArray[i])
       {
           pq.push({listArray[i]->data,listArray[i]});
       }
   }

   Node* dummyNode = new Node(-1);
   Node* temp = dummyNode;

   while (!pq.empty())
   {
       pair<int,Node*> p = pq.top();
       pq.pop();
       temp->next = p.second;
       if (p.second->next)
       {
           pq.push({p.second->next->data,p.second->next});
       }
       temp = temp->next;
   }
    return dummyNode->next;
}

int main()
{
     Node* list1 = new Node(1);
    list1->next = new Node(3);
    list1->next->next = new Node(5);

   
    Node* list2 = new Node(2);
    list2->next = new Node(4);
    list2->next->next = new Node(6);

 
    Node* list3 = new Node(0);
    list3->next = new Node(7);

  
    vector<Node*> listArray;
    listArray.push_back(list1);
    listArray.push_back(list2);
    listArray.push_back(list3);

    Node* head = mergeKLists(listArray);

    Node* temp = head;

    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->next;
    }

}