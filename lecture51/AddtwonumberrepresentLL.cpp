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
Node* solve(Node* &first,Node* &second){
    Node* curr1=first;
    Node* next1=curr1->next;
    Node* curr2=second;
    Node* next2=curr2->next;

    //if only one element is present in first list
    if(first->next==NULL){
        first->next=second;
        return first;
    }

    while(next1!=NULL && curr2!=NULL){
        if((curr2->data>=curr1->data)&&(curr2->data<=next1->data)){

            //add node between first list 
            curr1->next=curr2;
            next2=curr2->next;
            curr2->next=next1;

            //update pointers
            curr1=curr2;
            curr2=next2;
        }

        else{
            // curr1 aur next1 ko aagae badhao
            curr1=next1;
            next1=next1->next;
        }

        if(next1==NULL){
            curr1->next=curr2;
            return first;
        }
    }
    return first;
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
void insertatTail(Node* &head,Node* &tail,int val ){
    Node* temp=new Node(val);
    if(head==NULL){
        head=temp;
        tail=temp;
        return;
    }
    else{
        tail->next=temp;
        tail=temp;
    }

}
Node *add(Node *first,Node *second){
    int carry=0;
    Node *anshead=NULL;
    Node *anstail=NULL;
    while(first!=NULL && second!=NULL){
        int sum=carry+first->data+second->data;
        int digit=sum%10;
        insertatTail(anshead,anstail,digit);
        carry=sum/10;
        first=first->next;
        second=second->next;
    }

    while(first!=NULL){
        int sum=carry+first->data;
        int digit=sum%10;
        insertatTail(anshead,anstail,digit);
        carry=sum/10;
        first=first->next;
    }

    while(second!=NULL){
        int sum=carry+second->data;
        int digit=sum%10;
        insertatTail(anshead,anstail,digit);
        carry=sum/10;
        second=second->next;
    }

    while (carry!=0)
    {
        int sum=carry;
        int digit=sum%10;
        insertatTail(anshead,anstail,digit);
        carry=sum/10;

    }
    return anshead;
    
}
Node* addtwoList(Node* first , Node* second){
    //step1 reverse LL
    first=reverse(first);
    second=reverse(second);

    //step2 add content of both LL
    Node *ans=add(first,second);

    //step3 reverse ans
    ans=reverse(ans);
    return ans;
}

int main(){
    //created a new node
    Node *node1=new Node(4);
    Node* node2=new Node(3);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    //head pointed to node 1
    Node *head1=node1;
    Node *tail1=node1;
    Node *head2=node2;
    Node *tail2=node2;

    //print(head1);
    //print(head2);
    InsertatTail(tail1,5);
    print(head1);


    InsertatTail(tail2,4);

    InsertatTail(tail2,5);



    print(head2);

    Node *ans=addtwoList(head1,head2);
    print(ans);

    
}