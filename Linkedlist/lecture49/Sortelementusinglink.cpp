//nhi chlra code
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
        //MEMORY FREE
        if(this->next!=NULL){
            delete next;
            this->next=NULL;
        }
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
void insertAttail(Node* &tail,Node* &curr){
    tail->next=curr;
    tail=curr;
}
//create three separate linked-list
Node* Sort(Node* &head){
   Node *zerohead=new Node(-1);
   Node *zerotail=zerohead;
   Node *onehead=new Node(-1);
   Node *onetail=onehead;
   Node *twohead=new Node(-1);
   Node *twotail=twohead;

   Node*curr=head;
   while(curr!=NULL){
    int value=curr->data;
    if(value==0){
        insertAttail(zerotail,curr);
    }
    else if(value==1){
        insertAttail(onetail,curr);
    }
    else if(value==2){
        insertAttail(twotail,curr);
    }
    curr=curr->next;

   }

    //Merge linked list
    //1's list is non-empty
    if(onehead->next!=NULL){
        zerotail->next=onehead->next;
    }
    else{
        zerotail->next=twohead->next;
    }
    onetail->next = twohead->next;
    twotail->next=NULL;

    head=zerohead->next;
    //delete zerohead;
    //delete onehead;
    //delete twohead;

    return head;

}



int main(){
    //created a new node
    Node *node1=new Node(1);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    //head pointed to node 1
    Node *head=node1;
    Node *tail=node1;
    print(head);
    InsertatTail(tail,0);
    print(head);

    InsertatTail(tail,2);
    print(head);
    
    InsertatTail(tail,1);
    print(head);
    
    InsertatTail(tail,2);
    print(head);

    Node *ans=Sort(head);
    print(ans);



    
}