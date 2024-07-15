#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> reverseKelement(queue<int> &q,int k){
    stack<int> s;
    for(int i=0;i<k;i++){
        s.push(q.front());
        q.pop();
    }
    while(!s.empty()){
        q.push(s.top());
        s.pop();
    }
    for(int i=0;i<q.size()-k;i++){
        q.push(q.front());
        q.pop();
    }

    return q;
}




int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    int k;
    cout<<"Enter window size: "<<endl;
    cin>>k;
    queue<int> ans=reverseKelement(q,k);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }

    
}