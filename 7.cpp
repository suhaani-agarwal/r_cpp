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




bool isPallindrome(node *head, node*tail){
    
    while(tail!=head and tail->next != head){
        if(tail->data != head->data){
            return false;
        }
        head = head->next;
        tail = tail->prev;
    }
    return true;
}



int main(){

    int n;
    cin>>n;
    node *head = NULL;
    node *tail = NULL;
    for(int i =0 ;i<n; i++){
        int el;
        cin>>el;
        insertAtTail(head,el,tail);
    }
    if(isPallindrome(head, tail)){
        cout<<"true";
    }else{
        cout<<"false";
    }

}