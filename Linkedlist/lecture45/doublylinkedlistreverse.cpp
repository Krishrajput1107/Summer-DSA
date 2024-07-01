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
void insertatTail(Node* &tail,int d){
    Node *temp=new Node(d);
    tail->next=temp;
    temp->prev=tail;
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

Node* reverse(Node* &head) {
    Node *temp = NULL;
    Node *current = head;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        head = temp->prev;
    }
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

    Node *ans=reverse(head);
    print(ans);


}