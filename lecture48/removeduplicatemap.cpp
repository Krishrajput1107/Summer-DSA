#include<iostream>
#include<map>
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
Node* removeduplicate(Node*& head) {
    if (head == NULL) return NULL;

    Node* temp = head;
    Node* prev = NULL;
    map<int, bool> visited;

    while (temp != NULL) {
        if (visited[temp->data] == true) {
            Node* nodetodelete = temp;
            prev->next = temp->next;
            temp = temp->next;
            nodetodelete->next = NULL;
            delete nodetodelete;
        } else {
            visited[temp->data] = true;
            prev = temp;
            temp = temp->next;
        }
    }
    return head;
}

int main(){
    //created a new node
    Node *node1=new Node(4);
    //cout<<node1->data<<endl;
    //cout<<node1->next<<endl;

    //head pointed to node 1
    Node *head=node1;
    Node *tail=node1;
    print(head);
    InsertatTail(tail,5);
    print(head);

    InsertatTail(tail,5);
    print(head);

    InsertatTail(tail,2);
    print(head);

    InsertatTail(tail,2);
    print(head);

    InsertatTail(tail,7);
    print(head);

    InsertatTail(tail,1);
    print(head);

    InsertatTail(tail,1);
    print(head);

    InsertatTail(tail,1);
    print(head);

    InsertatTail(tail,3);
    print(head);

    InsertatTail(tail,3);
    print(head);

    removeduplicate(head);
    print(head);



    //cout<<head->data<<" ";
    //cout<<tail->data<<" ";

    
    
    
}