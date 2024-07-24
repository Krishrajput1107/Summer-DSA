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

Node* solve(int in[],int pre[],int &index,int inorderStart,int inorderEnd,int n){
    //base case if covered all elements of preorder
    if(index>=n || inorderStart>inorderEnd){
        return NULL;
    }

    int element=pre[index++];
    Node *root=new Node(element);
    int position=findPosition(in,element,n);

    //recursive calls
    root->left=solve(in,pre,index,inorderStart,position-1,n);
    root->right=solve(in,pre,index,position+1,inorderEnd,n);

    return root;

}

Node* buildtree(int in[],int pre[], int n){
    int preOrderIndex=0;
    Node *ans=solve(in,pre,preOrderIndex,0,n-1,n);
    return ans;
}

void postOrderTraversal(Node* root){
    if(root==NULL){
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
}

int main(){
    int in[]={3,1,4,0,5,2};
    int pre[]={0,1,3,4,2,5};
    int n=6;
    Node* ans=buildtree(in,pre,n);

    postOrderTraversal(ans);

}