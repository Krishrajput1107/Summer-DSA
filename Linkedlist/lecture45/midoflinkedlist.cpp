#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int d){
        this->data=d;
        this->next=NULL;
    }
};
void insertatTail(Node* &tail,int d){
    Node *temp=new Node(d);
    tail->next=temp;
    tail=temp;
}

void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}

int getLength(Node* &head){
    int len=0;
    Node *temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;

}

Node *Midnode(Node *head,int len){
    int ans=(len/2);
    Node *temp=head;
    int cnt=0;
    while(cnt<ans){
        temp=temp->next;
        cnt++;
    }
    return temp;
}


int main(){
    Node *node1=new Node(10);

    Node *tail=node1;
    Node *head=node1;
    print(head);
    insertatTail(tail,15);
    print(head);

    insertatTail(tail,20);
    print(head);

    insertatTail(tail,23);
    print(head);

    insertatTail(tail,31);
    print(head);

    insertatTail(tail,40);
    print(head);

    int length=getLength(head);
    
    Node* ans=Midnode(head,length);
    cout<<ans->data;

}