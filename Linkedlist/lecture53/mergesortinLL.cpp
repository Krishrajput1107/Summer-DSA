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

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head -> next;
    
    while(fast != NULL && fast -> next != NULL) {
        slow = slow -> next;
        fast = fast -> next -> next; 
    }
    return slow;
}
Node* merge(Node* &left,Node* &right){
    if(left==NULL){
        return right;
    }
    if(right==NULL){
        return left;
    }
    Node *ans=new Node(-1);
    Node *temp=ans;

    while(left!=NULL && right!=NULL){
        if(left->data < right->data){
            temp->next=left;
            temp=left;
            left=left->next;
        }
        else{
            temp->next=right;
            temp=right;
            right=right->next;
        }
    }

    while(left!=NULL){
        temp->next=left;
        temp=left;
        left=left->next;
    }

    while(right!=NULL){
        temp->next=right;
        temp=right;
        right=right->next;
    }
    ans=ans->next;
    return ans;
}

Node* mergeSort(Node* &head){
    if(head==NULL || head->next==NULL){
        return head;
    }
    //create right and left halves
        Node* mid=findMid(head);
        Node* left=head;
        Node* right=mid->next;
        mid->next=NULL;

        //recursive calls to sort both halves
        left=mergeSort(left);
        right=mergeSort(right);

        //merge both halves
        Node *result=merge(left,right);
        return result;

}

int main(){
    //created a new node
    Node *node1=new Node(5);
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

    InsertatTail(tail,11);
    print(head);

    InsertatTail(tail,3);
    print(head);

    InsertatTail(tail,7);
    print(head);

    InsertatTail(tail,1);
    print(head);

    Node* answer=mergeSort(head);
    print(answer);

    
}