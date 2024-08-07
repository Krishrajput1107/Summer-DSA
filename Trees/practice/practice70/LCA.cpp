#include <iostream>
#include <queue>
#include <climits>  // For INT_MIN and INT_MAX
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

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

Node* InsertInBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = InsertInBST(root->left, data);
    } else {
        root->right = InsertInBST(root->right, data);
    }
    return root;
}

void takeInput(Node*& root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    while (data != -1) {
        root = InsertInBST(root, data);
        cin >> data;
    }
}

Node* LCA(Node* root,int P,int Q){
    if(root==NULL){
        return NULL;
    }
    if(root->data<P && root->data<Q){
        LCA(root->right,P,Q);
    }
    if(root->data>P && root->data>Q){
        LCA(root->left,P,Q);
    }
    else{
        return root;
    }

}

Node* LCAo(Node* root,int P,int Q){
    if(root==NULL){
        return NULL;
    }
    while(root!=NULL){
        if(root->data>P && root->data> Q){
            root=root->left;
        }
        else if(root->data<P && root->data<Q){
            root=root->right;
        }
        else{
            return root;
        }
    }

}




int main() {
    Node* root = NULL;
    takeInput(root);
    int P=1;
    int Q=3;

    levelwise(root);
    Node* ans=LCAo(root,P,Q);
    cout<<"LCA IS: "<<ans->data;
    
    return 0;
}

// Example input: 4 2 5 1 3 -1
