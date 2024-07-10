#include<iostream>
using namespace std;
class Stack{
    public:
    int *arr;
    int top1;
    int top2;
    int size;

    Stack(int s){
        this->size=s;
        top1=-1;
        top2=s;
        arr=new int(s);
    }

    //push in stack1
    void push1(int num){
        //at least one empty space hai
        if(top2-top1>1){
            top1++;
            arr[top1]=num;
        }

        else{
            cout<<"Stack overflow "<<endl;
        }
    }
    //push in stack2
    void push2(int num){
        if(top2-top1>1){
            top2--;
            arr[top2]=num;
        }
        else{
            cout<<"Stack overflow "<<endl;
        }
    }

    int pop1(){
        if(top1>=0){
            int ans=arr[top1];
            top1--;
            return ans;
        }
        else{
            return -1;
        }
    }

    int pop2(){
        if(top2<size){
            int ans=arr[top2];
            top2++;
            return ans;
        }
        else{
            return -1;
        }
    }

    bool isEmpty(){
        if(top1==-1 && top2==size){
            return 1;
        }
        else{
            return 0;
        }
    }

    int peak1(){
        if(top1>=0){
            return arr[top1];
        }
        else{
            cout<<"Stack is empty "<<endl;
            return -1;
        }
    }

    int peak2(){
        if(top2<size){
            return arr[top2];
        }
        else{
            cout<<"Stack is empty "<<endl;
            return -1;
        }
    }


};


int main(){
    Stack s(5);
    s.push1(12);
    s.push1(14);
    s.push2(19);
    s.push2(20);

    cout<<"top element of stack 1 is: "<<s.peak1()<<endl;
    s.pop1();
    cout<<"top element of stack 1 is: "<<s.peak1()<<endl;

    cout<< s.isEmpty()<<endl;

    cout<<"top element of stack 2 is: "<<s.peak2()<<endl;

}