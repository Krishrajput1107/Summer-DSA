#include<iostream>
#include<vector>
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

    //distructor
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

void deleteNode(int position, Node* &head){
    //delteing first node
    if(position==1){
        Node *temp=head;
        head=head->next;
        //memory free krdo
        temp->next=NULL;
        delete temp;
    }
    //deleting any mid or last node
    else{
        Node *current=head;
        Node *prev=NULL;
        int cnt=1;
        while(cnt<position){
            prev=current;
            current=current->next;
            cnt++;
        }
        prev->next=current->next;
        current->next=NULL;
        delete current;
    }
}

Node *getMiddle(Node* &head){
    Node* slow=head;
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

Node* reverse(Node* &head){
    Node* curr=head;
    Node* prev=NULL;
    Node* forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->next=prev;
        prev=curr;
        curr=forward;
    }
    return prev;
}

bool isPalindrome(Node* &head){
    if(head==NULL || head->next==NULL){
        return true;
    }
    //step 1 middle
    Node* middle=getMiddle(head);

     //step 2 reverse list after middle
     Node* temp=middle->next;
     middle->next=reverse(temp);

     //step3 compare both halves
     Node* head1=head;
     Node* head2=middle->next;
     while(head2!=NULL){
        if((head1->data)!=(head2->data)){
            return false;
        }
        head1=head1->next;
        head2=head2->next;
     }

     //step4- repeat step 2
    temp=middle->next;
    middle->next=reverse(temp);

     return true;


}

int main(){
    //created a new node
    Node *node1=new Node(1);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    //head pointed to node 1
    Node *head=node1;
    Node *tail=node1;
    InsertatTail(tail,2);

    InsertatTail(tail,3);

    InsertatTail(tail,3);

    InsertatTail(tail,2);

    InsertatTail(tail,1);
    print(head);

    bool ans=isPalindrome(head);
    if(ans){
        cout<<"Linked list is palindrome "<<endl;
    }
    else{
        cout<<"Not palindrome "<<endl;
    }

    
   
}