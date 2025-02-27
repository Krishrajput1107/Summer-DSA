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
    ~Node(){
        int value=this->data;
        //MEMORY FREE
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
        cout<<"memory is free for node with data "<<value<<endl;
    }
};

void insertNode(Node* &tail, int element, int data){
    if(tail==NULL){
        Node *temp=new Node(data);
        tail=temp;
        temp->next=temp;
    }
    else{
        //non-empty list
        //assuming that element is present in the list
        Node *current=tail;
        while(current->data!=element){
            current=current->next;
        }
        //element found now current is representing element wala node
        Node *temp=new Node(data);
        temp->next=current->next;
        current->next=temp;

    }

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

void print(Node* &tail){
    Node *temp=tail;
    //empty list
    if(tail==NULL){
        cout<<"List is empty "<<endl;
        return;
    }

    do{
        cout<< tail -> data<<" ";
        tail=tail->next;
    }while(temp!=tail);
    cout<<endl;
    
}

int main(){
    Node* node1=new Node(10);
    Node* tail=NULL;
    insertNode(tail,5,3);
    print(tail);
    insertNode(tail,3,10);
    print(tail);
    insertNode(tail,3,5);
    print(tail);
    insertNode(tail,10,13);
    print(tail);
    insertNode(tail,5,17);
    print(tail);

    bool ans= Circular(tail);
    if(ans){
        cout<<"It is Circular"<<endl;
    }
    else{
        cout<<"It is not circular"<<endl;
    }


}