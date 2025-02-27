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

void levelwise(Node* &root){
    if(root==NULL){
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
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

void reverseLevelwise(Node* root) {
    if (root == NULL) {
        return;
    }
    
    queue<Node*> q;
    stack<Node*> s;
    q.push(root);

    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        s.push(temp);

        // Note that right child is enqueued before left child
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Now print all nodes in stack
    while (!s.empty()) {
        Node* temp = s.top();
        cout << temp->data << " ";
        s.pop();
    }
    cout << endl;
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

    cout<<"Priniting level order traversal: "<<endl;
    levelwise(root);

    cout<<"Printing reverse: "<<endl;
    reverseLevelwise(root);

}