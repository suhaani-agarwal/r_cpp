#include <iostream>
#include <cmath>
using namespace std;

class node
{
public:
    int data;
    node *next;
    node *prev;

    node(int d)
    {
        data = d;
        next = NULL;
        prev = NULL;
    }
};

void insertAtTail(node *&head, int d, node *&tail)
{

    if (head == NULL)
    {
        head = tail = new node(d);
        return;
    }
    node *n = new node(d);
    
    tail->next = n;
    n->prev = tail;
    tail = n;
}

void print(node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}

void kappend(node *head, int k, int n, node *tail){
    node * temp = head;
    for(int i = 0; i<n-k; i++){
        temp = temp->next;

    }
    // cout<<temp->data;
    node *tempend = tail;
    while(tempend!=temp->prev){
        tempend->next = head;
        head = tempend;
        tempend->prev->next = NULL;
        tempend = tempend->prev;
    }
    print(head);
}

int main(){
    int n;
    cin>>n;
    node *head = NULL;
    node *tail = NULL;
    for(int i = 0; i<n; i++){
        int el;
        cin>>el;
        insertAtTail(head, el, tail);
    }
    int k; 
    cin>>k;

    kappend(head, k, n, tail);
}