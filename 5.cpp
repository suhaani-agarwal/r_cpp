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

bool floydCycleRemoval(node *head)
{
    node *fast = head;
    node *slow = head;
    node *temp = head;
    while(fast!=NULL){
        fast = fast->next->next;
        slow = slow->next;
        if(slow == fast){
            return true;
        }
    }
    return false; 
}


int main(){

}