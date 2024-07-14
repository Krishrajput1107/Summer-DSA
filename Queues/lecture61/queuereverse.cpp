#include<iostream>
#include<queue>
#include<stack>
using namespace std;

void reverseQueue(queue<int> &q,int size){

    stack<int> s;
    while(!q.empty()){
        int element=q.front();
        s.push(element);
        q.pop();
    }

    while(!s.empty()){
        int top=s.top();
        q.push(top);
        s.pop();
    }
    return;

}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    int size=q.size();

    reverseQueue(q,size);

    while(!q.empty()){
        cout<<q.front()<<" ";
        q.pop();
    }
}