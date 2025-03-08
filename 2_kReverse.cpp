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
    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = n;
    n->next = NULL;
}

void print(node *head)
{

    while (head != NULL)
    {
        cout << head->data << " ";
        head = head->next;
    }
}


node* krev(node*head, int k){
    //base case:
    if(head == NULL){
        return head;
    }
    
    node *current = head;
    node *prev = NULL;
    int count = 0;

    //recursive case:
    while(current!=NULL and count<k){
        node *n = current->next;
        current->next = prev;
        prev = current;
        current = n;
        count++;
    }
    if(current!=NULL){
        head->next = krev(current,k);
    }
    return prev;
}


int main(){

    int n;
    int k;
    cin >> k >> n;
    node *head = NULL;
    for (int i = 0; i < n; i++){
        int el;
        cin >> el;
        insertAtTail(head, el);
    }

    head = krev(head, k);
    print(head);

}