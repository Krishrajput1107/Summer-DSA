#include<iostream>
using namespace std;

class node{
    public:
    int data;
    node *left;
    node *right;

    node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
    }
};

node* buildtree(node* root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    root=new node(data);
    if(data==-1){
        return NULL;
    }
    cout<<"Enter data for inserting in left of: "<<data<<endl;
    buildtree(root->left);

    cout<<"Enter data for inserting in right of: "<<data<<endl;
    buildtree(root->right);
    return root;
}



int main(){
    node* root=NULL;
    //cfreate a tree
    root=buildtree(root);
    

}