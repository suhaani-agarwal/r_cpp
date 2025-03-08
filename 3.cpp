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


void sep(node*&head){

    if(head == NULL){
        return;
    }

    node*temp = head;
    node*evenHead = NULL;
    node*oddHead = NULL;
    node*evenTail = NULL;
    node*oddTail = NULL;

    while(temp!=NULL){

        if(temp->data%2 == 0){
            if(evenHead == NULL){
                evenHead = temp;
                evenTail = temp;
            }
            else{
                evenTail->next = temp;
                
            }
        }else{
            if(oddHead == NULL){
                oddHead = temp;
                oddTail = temp;
            }else{
                oddTail->next = temp;
                
            }
        }
        
        temp = temp->next;
    }
    if(temp==NULL){
        evenTail->next = NULL;
        oddHead = evenTail;
        head = oddHead;
    }
    
}



int main(){

    node*head = NULL;

    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int el;
        cin>>el;
        insertAtTail(head,el);
    }

    sep(head);
    print(head);

}