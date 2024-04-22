#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *next;
    Node *child;
    Node() : data(0), next(nullptr), child(nullptr){};
    Node(int x) : data(x), next(nullptr), child(nullptr) {}
    Node(int x, Node *next, Node *child) : data(x), next(next), child(child) {}
};


Node* mergeLL(Node* head1, Node* head2)
{
	Node* dummyNode = new Node(-1);
	Node* res = dummyNode;

	while (head1 != NULL && head2 != NULL)
	{
		if (head1->data < head2->data)
		{
			res -> child = head1;
			res = head1;
			head1 = head1->child;
		}
		else if (head1->data > head2->data)
		{
			res-> child = head2;
			res = head2;
			head2 = head2->child;
		}

	}
	while (head1) {
		res->child = head1;
		res = head1;
		head1 = head1->child;
	}
	while (head2){
		res->child = head2;
		res = head2;
		head2 = head2->child;
	}
	return dummyNode->child;
}
Node* flattenLinkedList(Node* head) 
{
	if (head == NULL || head->next == NULL)
	{
		return head;
	}
	Node* returnedHead = flattenLinkedList(head->next);
	
	return mergeLL(head,returnedHead);

}
int main()
{
    Node* firstHead = new Node(1);
    firstHead->child = new Node(2);
    firstHead->next = new Node(4);
    firstHead->next->child = new Node(5);
    firstHead->next->next = new Node(3);
    firstHead->next->next->child = new Node(6);
    firstHead->next->next->child->child = new Node(7);   
  
    cout << endl;
    
    Node* temp = flattenLinkedList(firstHead);
    
    while (temp != NULL)
    {
        cout << temp->data << ' ';
        temp = temp->child;
    }

 
}
