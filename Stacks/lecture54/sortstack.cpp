#include<iostream>
#include<stack>
using namespace std;

void sortInsert(stack<int> &s,int element){
    if(s.empty() || !s.empty() && s.top()<element){
        s.push(element);
        return;
    }
    int n=s.top();
    s.pop();

    sortInsert(s,element);

    s.push(n);

}

void sortStack(stack<int> &s){
    if(s.empty()){
        return;
    }

    int element=s.top();
    s.pop();

    //recursive call
    sortStack(s);

    sortInsert(s,element);

}


int main(){
    stack<int> s;
    s.push(5);
    s.push(-2);
    s.push(9);
    s.push(-7);
    s.push(3);

    sortStack(s);

     while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}