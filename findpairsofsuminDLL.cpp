#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *prev;
    Node *next;
    Node()
    {
        this->data = 0;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data)
    {
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }
    Node(int data, Node *next, Node *prev)
    {
        this->data = data;
        this->prev = prev;
        this->next = next;
    }
};

Node *findTail(Node *head)
{
    Node *temp = head;
    while (temp->next != NULL)
        temp = temp->next;
    return temp;
}

vector<pair<int, int>> findPairs(Node *head, int k)
{
    vector<pair<int, int>> ans;
    if (head == NULL)
        return ans;

    Node *left = head;
    Node *right = findTail(head);

    while (left->data < right->data)
    {
        int sum = left->data + right->data;
        if (sum == k)
        {
            ans.push_back({left->data, right->data});
            left = left->next;
            right = right->prev;
        }
        else if (sum < k)
        {
            left = left->next;
        }
        else
            right = right->prev;
    }
    return ans;
}

int main()
{
    Node *firstHead = new Node(1);
    firstHead->prev = NULL;
    firstHead->next = new Node(2);
    firstHead->next->prev = firstHead;
    firstHead->next->next = new Node(3);
    firstHead->next->next->prev = firstHead->next;

    firstHead->next->next->next = new Node(4);
    firstHead->next->next->next->prev = firstHead->next->next;

    cout << endl;

    for (auto x: findPairs(firstHead, 5))
    {
        cout << x.first << " " << x.second << endl;
    }
    
}
