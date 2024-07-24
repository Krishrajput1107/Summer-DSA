#include<iostream>
#include<stack>
#include<queue>
#include<map>
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

int findPosition(int in[],int element,int n){
    for(int i=0;i<n;i++){
        if(in[i]==element){
            return i;
        }
    }
    return -1;
}

Node* solve(int in[],int post[],int &index,int inorderStart,int inorderEnd,int n){
    //base case if covered all elements of preorder
    if(index<0 || inorderStart>inorderEnd){
        return NULL;
    }

    int element=post[index--];
    Node *root=new Node(element);
    int position=findPosition(in,element,n);

    //recursive calls
    //In case of post order and in order first build right subtreee
    root->right=solve(in,post,index,position+1,inorderEnd,n);
    root->left=solve(in,post,index,inorderStart,position-1,n);

    return root;

}

Node* buildtree(int in[],int pre[], int n){
    int postOrderIndex=n-1;
    Node *ans=solve(in,pre,postOrderIndex,0,n-1,n);
    return ans;
}

void preOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
}

int main(){
    int in[]={4,8,2,5,1,6,3,7};
    int post[]={8,4,5,2,6,7,3,1};
    int n=8;
    Node* ans=buildtree(in,post,n);

    preOrderTraversal(ans);

}