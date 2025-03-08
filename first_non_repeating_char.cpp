#include <iostream>
#include <queue>
using namespace std;

int main(){

    queue<char> q;
    char ch;
    cin>>ch;
    char freq[27] = {'0'};
    while(ch!='.'){

        q.push(ch);
        freq[ch-'a']++;
        //query
        while(!q.empty()){
            int indx = q.front()-'a';
            if(freq[indx]>1){
                q.pop();
            }else{
                cout<<q.front()<<" ";
                break;
            }
        }
        if(q.empty()){
            cout<<"-1"<<" ";
        }
        cin>>ch;
    }
    

}