#include<iostream>
#include<queue>
#include<stack>
#include<map>
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

void solve(Node* root, vector<int> &ans, int lvl){
    if(root==NULL){
        return;
    }

    if(lvl==ans.size()){
        ans.push_back(root->data);
    }
    
    solve(root->right,ans,lvl+1);
    solve(root->left,ans,lvl+1);

}


vector<int> rightViewOrder(Node *root)
    {   
        vector<int> ans;
        solve(root,ans,0);

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

    vector<int>answer=rightViewOrder(root);
    cout<<"Priniting Right view: "<<endl;

    for(int i=0;i<answer.size();i++){
        cout<<answer[i]<<" ";
    }

    // 1 2 3 -1 -1 4 -1 7 -1 -1 5 -1 6 -1 8 -1 9 -1 -1 

}