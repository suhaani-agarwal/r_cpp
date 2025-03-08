#include <iostream>
#include <queue>
#include <vector>
using namespace std;

void first_negative(int arr[],vector<int> &result, int n, int k){
    queue<int> neg_indexes;
    for(int i = 0; i<n; ++i){
        int current = arr[i];
        
        if(current<0){
            neg_indexes.push(i);
        }
        if(!neg_indexes.empty() and neg_indexes.front() < i-k+1){
            neg_indexes.pop();
        }
        if(i>=k-1){
            if(!neg_indexes.empty()){
                result.push_back(arr[neg_indexes.front()]);
            }else{
                result.push_back(0);
            }
        }
        
    }


}


int main(){
    
    vector<vector<int> > f_result;
    int t;
    cin>>t;
    for(int i = 0; i<t; i++){
        vector<int> result;
        int n, k;
        cin>>n>>k;
        int arr[n];
        for(int j = 0; j<n; j++){
            int el;
            cin>>el;
            arr[j] = el;
        }
        first_negative(arr,result,n,k);
        
        f_result.push_back(result);
    }
    for(auto x:f_result){
        for(int y:x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
}