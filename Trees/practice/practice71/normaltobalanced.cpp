#include <iostream>
#include <queue>
#include<vector>
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
void inorder(Node* root,vector<int> &in){
    if(root==NULL){
        return;
    }
    inorder(root->left,in);
    in.push_back(root->data);
    inorder(root->right,in);
}

Node* NormaltobalanceBST(int s,int e,vector<int> in){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    Node* root=new Node(in[mid]);
    root->left=NormaltobalanceBST(s,mid-1,in);
    root->right=NormaltobalanceBST(mid+1,e,in);

    return root;
}

Node* NormaltoBalance(Node* root){
    vector<int> in;
    inorder(root,in);

    return NormaltobalanceBST(0,in.size()-1,in);
}

int main() {
    Node* root = NULL;
    takeInput(root);
    levelwise(root);

    Node* ans=NormaltoBalance(root);
    cout<<"After balancing:" <<endl;
    levelwise(root);

    


    return 0;
}

// Example input: 10 7 3 9 5 11 14 18 19 21 23 -1
