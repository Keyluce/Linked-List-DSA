#include <bits/stdc++.h>
using namespace std;
class Node
{

public:
    string data;
    Node *next;
    Node *prev;

    Node(string data)
    {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
    Node(string data, Node *next)
    {
        this->data = data;
        this->next = next;
        this->prev = NULL;
    }
    Node(string data, Node *next, Node *prev)
    {
        this->data = data;
        this->next = next;
        this->prev = prev;
    }
};
class Browser
{
    Node *current;

public:
    Browser(string &homepage)
    {
        this->current = new Node(homepage);
    }

    void visit(string &url)
    {
        Node *newPage = new Node(url);
        newPage->prev = current;
        current->next = newPage;
        current = current->next;
    }

    string back(int steps)
    {
        while (steps)
        {
            if (current->prev)
            {
                this->current = current->prev;
            }
            else
            {
                break;
            }
            steps--;
        }
        return current->data;
    }

    string forward(int steps)
    {
        while (steps)
        {
            if (current->next)
            {
                current = current->next;
            }
            else
            {
                break;
            }
            steps--;
        }
        return current->data;
    }
};

int main()
{
    string homepage = "www.homepage.com";
    Browser browser(homepage);

 
    string url1 = "www.page1.com";
    string url2 = "www.page2.com";
    string url3 = "www.page3.com";

    browser.visit(url1);
    browser.visit(url2);
    browser.visit(url3);

   
    cout << "Current page: " << browser.back(1) << endl; 
    cout << "Current page: " << browser.back(1) << endl; 
    cout << "Current page: " << browser.back(1) << endl; 
    cout << "Current page: " << browser.back(1) << endl; 

  
    cout << "Current page: " << browser.forward(1) << endl; 
    cout << "Current page: " << browser.forward(2) << endl; 
    cout << "Current page: " << browser.forward(1) << endl; 

    return 0;
}
