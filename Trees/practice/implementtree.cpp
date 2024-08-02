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
    
    cout<<"Enter data in left of "<< root->data <<endl;
    root->left=buildtree(root->left);

    cout<<"Enter data in right of: "<< root->data<<endl;
    root->right=buildtree(root->right);

    return root;
}



int main(){
    Node* root=NULL;
    root=buildtree(root);
}