#include<iostream>
using namespace std;

class Stack{
    //data members
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size=size;
        arr=new int[size];
        top=-1;
    }

    void push(int element){
        if(size-top>1){
            top++;
            arr[top]=element;
        }
        else{
            cout<<"Stack overflow "<<endl;
        }
    }

    void pop(){
        if(top>=0){
            top--;
        }
        else{
            cout<<"Stack underflow "<<endl;
        }
    }

    int peak(){
        if(top>=0 && top<size){
            return arr[top];
        }
        else{
            cout<<"Stack is empty "<<endl;
            return -1;
        }
    }

    bool isEmpty(){
        if(top==-1){
            return 1;
        }
        else{
            return 0;
        }
    }
};



int main(){
    Stack st(5);
    st.push(1);
    st.push(2);
    st.push(3);

    st.pop();

    cout<< st.peak()<<endl;
    cout<< st.isEmpty();

}