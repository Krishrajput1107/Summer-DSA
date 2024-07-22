#include<iostream>
#include<queue>
#include<stack>
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

void Traversalleft(Node*root , vector<int> &ans){

    if( (root==NULL) || (root->left==NULL || root->right==NULL)){
        return;
    }
    ans.push_back(root->data);
    if(root->left)
        Traversalleft(root->left,ans);
    else
        Traversalleft(root->right,ans);    
}

void leafTraversal(Node* root,vector<int> &ans){

    if(root==NULL)
        return;

    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
        return;
    }

    leafTraversal(root->left,ans);
    leafTraversal(root->right,ans);

}

void rightTraversal(Node* root, vector<int> &ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    if (root->right)
        rightTraversal(root->right, ans);
    else
        rightTraversal(root->left, ans);

    ans.push_back(root->data); // add after child visit (reverse)
}


vector<int> Boundary(Node* root){
    vector<int> ans;
    if(root==NULL){
        return ans;
    }
    ans.push_back(root->data);
    //left part store
    Traversalleft(root->left,ans);

    //traverse leafnodes

    //left subtree
    leafTraversal(root->left,ans);

    //right subtree
    leafTraversal(root->right,ans);

    rightTraversal(root->right,ans);

    return ans;
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
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    buildtree(root);

    vector<int>answer=Boundary(root);
    cout<<"Priniting boundary order traversal: "<<endl;

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    // 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1

}