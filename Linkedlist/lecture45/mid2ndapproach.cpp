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

Node* Midnode(Node* &head){
    if((head==NULL) || (head->next==NULL)){
        return head;
    }

    if(head->next->next==NULL){
        return head->next;
    }
     Node *slow=head;
     Node *fast=head->next;

     while(fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
     }

     return slow;
    
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

    
    Node* ans=Midnode(head);
    cout<<ans->data;

}