#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};

class Stack{
    public:
    Node* top;
    // Constructor
    Stack() {
        top = NULL;
    }

    void push(int element){
        Node *newNode=new Node(element);
        if(top==NULL){
            top=newNode;
        }
        else{
            newNode->next=top;
            top=newNode;
        }
    }

    void pop(){
        Node *temp=top;
        if(temp==NULL){
            cout<<"Stack underflow"<<endl;
        }
        else{
            top=top->next;
            delete temp;
        }
        cout<<"element popped from stack "<<endl;
    }

    void peak(){
        if(top==NULL){
            cout<<"Stack empty"<<endl;
        }
        else{
            cout<<"Peak element is:" << top->data<<endl;
        }
    }

    bool isEmpty(){
        return top==NULL;
    }
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};
int main(){
    Stack s;
    s.push(10);
    s.push(15);
    s.push(23);

    s.peak();
    s.pop();

    s.peak();

    cout<<s.isEmpty();


}