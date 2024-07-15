#include<iostream>
#include<queue>
#include<stack>
using namespace std;

queue<int> Interleave(queue<int> q,int n){
    stack<int> s;
    for(int i=0;i<n;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }
    for(int i=0;i<n;i++){
        int val=s.top();
        s.pop();
        q.push(val);
    }

    for(int i=0;i<n;i++){
        int val=q.front();
        q.pop();
        q.push(val);
    }

    for(int i=0;i<n;i++){
        int val=q.front();
        q.pop();
        s.push(val);
    }

    while(!s.empty()){
        int val=s.top();
        s.pop();
        q.push(val);
        val=q.front();
        q.pop();
        q.push(val);
    }

    return q;



}

int main(){
    queue<int> q;
    q.push(11);
    q.push(12);
    q.push(13);
    q.push(14);
    q.push(15);
    q.push(16);
    q.push(17);
    q.push(18);
    int s=q.size()/2;

    queue<int> ans=Interleave(q,s);

    while(!ans.empty()){
        cout<<ans.front()<<" ";
        ans.pop();

    }
}
