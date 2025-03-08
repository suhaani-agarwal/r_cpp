#include <iostream>
#include <cmath>
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

node *take_input(){

    node *head = NULL;
    int d;
    cin>>d;
    while(d!=-1){
        insertAtTail(head,d);
        cin>>d;
    }
    return head;
}

int kthend(node *head, int k){

    if(head == NULL){
        return head->data;
    }

    node *fast = head;
    node *slow = head;
    while(k>0){
        fast = fast->next;
        k--;
    }
    while(fast!=NULL){
        slow= slow->next;
        fast = fast->next;
    }
    return slow->data;

}


int main(){

    node *head = take_input();
    int k;
    cin>>k;
    cout<<kthend(head,k);

    
}