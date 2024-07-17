#include<iostream>
#include<queue>
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

node* buildtree(node* &root){

    cout<<"Enter the data: "<<endl;
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    root=new node(data);
    cout<<"Enter data for inserting in left of: "<<data<<endl;
    buildtree(root->left);

    cout<<"Enter data for inserting in right of: "<<data<<endl;
    buildtree(root->right);
    return root;
}

void levelOrderTraversal(node* &root) {
    if (root == NULL) {
        return;
    }

    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while (!q.empty()) {
        node *temp = q.front();
        q.pop();

        if(temp==NULL){
            //purana level complete traverse hoo chuka hai
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }
        else{
            cout<<temp->data<<" ";
            if (temp->left) {
            q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }

        }
    }
}




int main(){
    node* root=NULL;
    //cfreate a tree
    root=buildtree(root);
    //1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"Printing level order traversal: "<<endl;
    levelOrderTraversal(root);


}