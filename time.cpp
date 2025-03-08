#include <iostream>
#include <queue>
using namespace std;

int main(){
    queue<int> q_calling, q_ideal;
    int n;
    cin>>n;
    for(int i = 0; i<n; i++){
        int el;
        cin>>el;
        q_calling.push(el);
    }
    for(int i = 0; i<n; i++){
        int el;
        cin>>el;
        q_ideal.push(el);
    }
    int time = 0;

    while(!q_calling.empty()){
        if(q_calling.front() == q_ideal.front()){
            q_calling.pop();
            q_ideal.pop();
            time++;
        }else{
            int element = q_calling.front();
            q_calling.pop();
            q_calling.push(element);
            time++;
        }
    }
    cout<<time;

}