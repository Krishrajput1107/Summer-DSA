#include<iostream>
#include<stack>
using namespace std;
void InsertatBottom(stack<int> &s,int size,int x){
    if(s.empty()){
        s.push(x);
        return;
    }
    int num=s.top();
    s.pop();
    InsertatBottom(s,size,x);

    s.push(num);
}


int main(){
    stack<int> s;
    s.push(12);
    s.push(14);
    s.push(21);
    s.push(7);
    int size=s.size();
    int x;
    cout<<"Enter element to be inserted "<<endl;
    cin>>x;
    InsertatBottom(s,size,x);

    while(!s.empty()){
        cout<<s.top()<<endl;
        s.pop();
    }
}