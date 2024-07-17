#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }

};

void levelwise(Node* &root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        cout<<temp->data<<" ";
        q.pop();
        if (temp->left) {
            q.push(temp->left);
        }
        if (temp->right) {
            q.push(temp->right);
        }
    }

}

Node* buildtree(Node* &root){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;

    if(data==-1){
        return NULL;
    }

    root=new Node(data);

    
    cout<<"Insert data inserting at left of "<<data<<endl;
    buildtree(root->left);

    cout<<"Insert data inserting at right of "<<data<<endl;
    buildtree(root->right);

    return root;

}


int main(){
    Node *root=NULL;
    buildtree(root);

    cout<<"Priniting level order traversal: "<<endl;
    levelwise(root);

}