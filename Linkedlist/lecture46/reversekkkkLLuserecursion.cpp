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

Node* reverse(Node* &head, int k){
    if(head==NULL){
        return NULL;
    }
    //Step 1 reverse K nodes
    Node *forward=NULL;
    Node *curr=head;
    Node *prev=NULL;
    int cnt=0;
    while((curr!=NULL)&&(cnt<k)){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
        cnt++;
    }
    //Step 2 recursion krega baaki sab
    if(forward!=NULL){
        head->next=reverse(curr,k);
    }

    //Step 3
    return prev;
}

int main(){
    int k;
    cout<<"enter value of k: "<<endl;
    cin>>k;
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

    Node *ans=reverse(head,k);
    print(ans);


}