#include<iostream>
#include<queue>
#include<stack>
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

void levelorderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
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

void reverselevelorderTraversal(Node*root){
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

        // Push left before right because we want right to appear before left in reverse order
        if (temp->right) {
            q.push(temp->right);
        }
        if (temp->left) {
            q.push(temp->left);
        }
    }

    // Output nodes in reverse order
    while (!s.empty()) {
        cout << s.top()->data << " ";
        s.pop();
    }
    cout << endl;
}

void preorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

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
void buildfromLevelOrder(Node* &root){
    queue<Node*> q;
    int data;
    cin>>data;
    root=new Node(data);
    q.push(root);
    while(!q.empty()){
        Node* temp=q.front();
        q.pop();
        cout<<"Enter data in left of "<<temp->data<<endl;
        int leftdata;
        cin>>leftdata;
        if(leftdata!=-1){
            temp->left=new Node(leftdata);
            q.push(temp->left);
        }

        cout<<"Enter data in right of "<<temp->data<<endl;
        int rightdata;
        cin>>rightdata;
        if(rightdata!=-1){
            temp->right=new Node(rightdata);
            q.push(temp->right);
        }
    }
}




int main(){
    Node* root=NULL;
    buildfromLevelOrder(root);
    levelorderTraversal(root);
    /*
    root=buildtree(root);

    cout<<"Level order traversal is: "<<endl;
    levelorderTraversal(root);

    cout<<"Reverse level order is: "<<endl;
    reverselevelorderTraversal(root);

    cout<<"Preorder: "<<endl;
    preorder(root);
    cout<<endl;

    cout<<"Inorder: "<<endl;
    inorder(root);
    cout<<endl;

    cout<<"Postorder: "<<endl;
    postorder(root);

    //2 3 4 -1 -1 -1 5 -1 -1
    */
}