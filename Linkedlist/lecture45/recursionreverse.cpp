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

void reverse(Node* &head,Node* &curr,Node* &prev){
    if(curr==NULL){
        head=prev;
        return;
    }
    Node *forward=curr->next;
    reverse(head,forward,curr);
    curr->next=prev;
}

Node* reverseLinkedlist(Node* &head){
    Node *curr=head;
    Node *prev=NULL;
    reverse(head,curr,prev);
    return head;
    
}

int main(){
    Node *node1=new Node(10);
    //cout<<node1->data<<endl;
    //cout<<node1->next;
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

    Node *ans=reverseLinkedlist(head);
    print(ans);


}