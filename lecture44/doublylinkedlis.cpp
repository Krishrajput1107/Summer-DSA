#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;
    Node *prev;

    Node(int d){
        this->data=d;
        this->next=NULL;
        this->prev=NULL;
    }
};
//traversing a linked list
void print(Node* &head){
    Node *temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
//get length
int getLength(Node* &head){
    int len=0;
    Node *temp=head;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertatHead(Node* &head,Node* &tail,int data){
    if(head==NULL){
        Node *temp=new Node(data);
        head=temp;
        tail=temp;
    }
    else{
        Node *temp=new Node(data);
        temp->next=head;
        head->prev=temp;
        head=temp;
    }
}
void insertatTail(Node* &head,Node* &tail,int data){
    if(tail==NULL){
        Node *temp=new Node(data);
        tail=temp;
        head=temp;
    }
    else{
        Node *temp=new Node(data);
        tail->next=temp;
        temp->prev=tail;
        tail=temp;
    }
}
void insertatPosition(Node*&tail, Node* &head,int position,int data){
    if(position==1){
        insertatHead(head,tail,data);
        return;
    }
    int cnt=1;
    Node *temp=head;
    while(cnt<position-1){
        temp=temp->next;
        cnt++;
    }
    //Insert at last position
    if(temp->next==NULL){
        insertatTail(head,tail,data);
        return;
    }

    //Insert at any position
    Node *nodetoInsert=new Node(data);
    nodetoInsert->next=temp->next;
    temp->next->prev=nodetoInsert;
    temp->next=nodetoInsert;
    nodetoInsert->prev=temp;
}
int main(){
    Node *node1=new Node(10);
    Node *head=node1;
    Node *tail=node1;
    print(head);
    //cout<<getLength(head)<<endl;
    insertatHead(head,tail,11);
    print(head);

    //cout<<getLength(head)<<endl;
    insertatTail(head,tail,14);
    print(head);

    insertatTail(head,tail,18);
    print(head);

    insertatPosition(tail,head,4,20);
    print(head);
    
}