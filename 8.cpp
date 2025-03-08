#include <iostream>
#include <cmath>
using namespace std;

class node{

    public:
    int data;
    node *next;

    node(int d){
        data = d;
        next = NULL;
    }

};

void insertAtTail(node *&head, int d){
    if(head==NULL){
        head = new node(d);
        return;
    }
    node*tail = head;
    while(tail->next!=NULL){
        tail = tail->next;
    }
    tail->next = new node(d);

}

void print(node*head){

    while(head!=NULL){
        cout<<head->data;
        if(head->next!=NULL){
            cout<<" ";
        }
        head = head->next;
    }

}

void del_Left_If_Right_Greater(node *&head){
    if(head == NULL or head->next == NULL){
        return;
    }

    if(head!=NULL and head->next!=NULL and head->data<head->next->data){
        node *temp = head;
        head = head->next;
        delete temp;
    }


    node *prev = head;
    node *current = head->next;
    while(current!=NULL && current->next!=NULL){
        if(current->next->data > current->data){
            prev->next = current->next;
            delete current;
            current = prev->next;
        }else{
            prev = current;
            current = current->next;

        }
        
    }
    
}




int main(){

    node *head = NULL;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int el;
        cin>>el;
        insertAtTail(head,el);
    }
    del_Left_If_Right_Greater(head);
    print(head);

}