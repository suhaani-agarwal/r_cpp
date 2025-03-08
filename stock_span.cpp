#include <iostream>
#include <stack>
using namespace std;

void stock_span(int n, int prices[], int span[]){
    stack<int> s;
    s.push(0);
    span[0] = 1;
    for(int i = 1; i<=n; i++){
        int currentPrice = prices[i];
        while(!s.empty() and currentPrice>=prices[s.top()]){
            s.pop();
        }
        if(!s.empty()){
            int prevHighest = s.top();
            span[i] = i - prevHighest;
        }else{
            span[i] = i+1;
        }
        s.push(i);
    }
    for(int i = 0; i<n; i++){
        cout<<span[i]<<" ";
    }
    cout<<"END";
}


int main(){
    int n;
    cin>>n;
    int prices[n];
    for(int j=0; j<n; j++){
        int el;
        cin>>el;
        prices[j] = el;
    }
    int span[n];
    stock_span(n,prices,span);

}

