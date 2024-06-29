#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node *next;

    //constructor
    Node(int data){
        this->data=data;
        this->next=NULL;
    }
};
void InsertatHead(Node* &head,int d){
    Node *temp=new Node(d);
    temp->next=head;
    head=temp;

}
void InsertatTail(Node* &tail, int d){
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
void InsertAtposition(Node* &tail,Node * &head,int position,int d){
    //insert at startposition
    if(position==1){
        InsertatHead(head,d);
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
        InsertatTail(tail,d);
        return;
    }

    //Insert at any position
    Node *nodetoInsert=new Node(d);
    nodetoInsert->next=temp->next;
    temp->next=nodetoInsert;
}


int main(){
    //created a new node
    Node *node1=new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    //head pointed to node 1
    Node *head=node1;
    Node *tail=node1;
    print(head);
    InsertatTail(tail,12);
    print(head);

    InsertatTail(tail,15);
    print(head);

    InsertAtposition(tail,head,4,20);
    print(head);


    
}