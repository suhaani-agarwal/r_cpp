#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int d)
    {
        data = d;
        next = NULL;
    }
};

void insertAtTail(node *&head, int d)
{

    if (head == NULL)
    {
        head = new node(d);
        return;
    }
    node *n = new node(d);
    node *temp = head;
    while(temp->next!=NULL){
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
    
}
void print(node *head)
{

    while (head != NULL)
    {
        cout << head->data << " -> ";
        head = head->next;
    }
}



node *merge(node *a, node *b)
{
    if (a == NULL)
    {
        return b;
    }
    if (b == NULL)
    {
        return a;
    }
    node *c;
    if (a->data < b->data)
    {
        c = a;
        c->next = merge(a->next, b);
    }
    else
    {
        c = b;
        c->next = merge(a, b->next);
    }

    return c;
}

int main()
{

    int t;
    cin >> t;

    vector<vector<int> > all;

    for (int i = 0; i < t; i++)
    {
        int n1;
        cin >> n1;
        node *a = NULL;
        for (int j = 0; j < n1; j++)
        {
            int el;
            cin >> el;
            insertAtTail(a, el);
        }
        int n2;
        cin >> n2;
        node *b = NULL;
        for (int j = 0; j < n2; j++)
        {
            int el;
            cin >> el;
            insertAtTail(b, el);
        }

        node*c = merge(a,b);
        vector<int> v;
        node *temp = c;
        while (temp != NULL)
        {
            v.push_back(temp->data);
            temp = temp->next;
        }
        all.push_back(v);
        
    }

    for(auto it : all){
        for(int k:it){
            cout<<k<<" ";
        }
        cout<<endl;
    }
    
}