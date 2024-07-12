#include<iostream>
#include<queue>
using namespace std;
int main(){
    queue<int> q;
    q.push(11);
    q.push(15);
    q.push(17);
    cout<<"Size of queue is: "<<q.size()<<endl;
    cout<<"Front of queue is: "<<q.front()<<endl;

    q.pop();
    cout<<"Size of queue is: "<<q.size()<<endl;

    cout<<"Front of queue is: "<<q.front()<<endl;

    q.pop();
    q.pop();
    cout<<"Size of queue is: "<<q.size()<<endl;

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty "<<endl;
    }


}