#include<iostream>
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

    cout<<"enter data: "<<endl;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new Node(data);
    
    root->left=buildtree(root->left);

    root->right=buildtree(root->right);
}



int main(){
    Node* root=NULL;
    root=buildtree(root);
}