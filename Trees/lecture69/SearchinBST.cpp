#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;  // Corrected this line to assign 'd' directly
        this->left = NULL;
        this->right = NULL;
    }
};



Node* InsertInBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left=InsertInBST(root->left, data);
    } else {
        root->right=InsertInBST(root->right, data);
    }

    
}

void takeInput(Node*& root) {  // Modified to take Node*& to modify the original root
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    while (data != -1) {
        root = InsertInBST(root, data);  // Modified to update the original root
        cin >> data;
    }
}

void levelwise(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            // Current level has been completely traversed
            cout << endl;
            if (!q.empty()) {
                // Queue still has some child nodes
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

bool Search(Node* root,int X){
    if(root==NULL){
        return false;
    }
    if(root->data==X){
        return true;
    }

    if(root->data>X){
        Search(root->left,X);
    }
    else{
        Search(root->right,X);
    }
}

void inorder(Node* root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    inorder(root->left);
    inorder(root->right);
}

int main() {
    Node* root = NULL;
    takeInput(root);
    int X;
    cout<<"Enter the value of X: "<<endl;
    cin>>X;
    bool ans=Search(root,X);
    if(ans){
        cout<<"Present"<<endl;
    }
    else{
        cout<<"Absent"<<endl;
    }
    levelwise(root);
    cout<<endl;
    inorder(root);


    return 0;
}

// Example input: 10 8 21 7 27 5 4 3 -1
