#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

Node* buildtree(Node* root){
    int data;
    cout<<"Enter the data: "<<endl;
    cin>>data;
    root=new Node(data);

    if(data==-1){
        return NULL;
    }
    cout<<"Enter the data in left of "<<data<<endl;
    buildtree(root->left);

    cout<<"Enter the data in right of "<<data<<endl;
    buildtree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        if(temp==NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}

int main(){
    Node* root=NULL;
    buildtree(root);

    cout<<"Printing data in level wise order: "<<endl;
    levelOrderTraversal(root);
}