#include<iostream>
#include<stack>
using namespace std;

void InsertatBottom(stack<int> &s,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    InsertatBottom(s,x);

    s.push(num);
}

void reverse(stack<int> &s){
    if(s.empty()){
        return;
    }
    int num=s.top();
    s.pop();
    reverse(s);

    InsertatBottom(s,num);
}




int main(){
    stack<int> s;
    s.push(9);
    s.push(7);
    s.push(4);
    s.push(3);
    int size=s.size();
    reverse(s);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}