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

bool Circular(Node* &head){
    if(head==NULL){
        return true;
    }
    if(head->next==NULL){
        return false;
    }
    if(head->next==head){
        return true;
    }
    Node *temp=head->next;
    while((temp!=NULL)&&(temp!=head)){
        temp=temp->next;
    }
    if(temp==NULL){
        return false;
    }
    if(temp==head){
        return true;
    }
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

    insertatTail(tail,42);
    print(head);

    bool ans= Circular(head);
    if(ans){
        cout<<"It is Circular"<<endl;
    }
    else{
        cout<<"It is not circular"<<endl;
    }


}