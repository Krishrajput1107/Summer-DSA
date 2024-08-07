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

void inordertarversal(Node* root, vector<int> &v){
    if(root==NULL){
        return;
    }
    inordertarversal(root->left,v);
    v.push_back(root->data);
    inordertarversal(root->right,v);
}

bool isValid(Node* root){
    vector<int> ans;
    inordertarversal(root,ans);
    for(int i=1;i<ans.size();i++){
        if(ans[i]<ans[i-1]){
            return false;
        }
    }
    return true;
}

bool isBST(Node* root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->data>=min && root->data<=max){
        bool left=isBST(root->left,min,root->data);
        bool right=isBST(root->right,root->data,max);
        return left && right;
    }
    else{
        return false;
    }
}

bool validBST(Node* root){
    return isBST(root,INT16_MIN,INT16_MAX);
}

int main() {
    Node* root = NULL;
    takeInput(root);

    levelwise(root);

    cout << (validBST(root) ? "The tree is a valid BST" : "The tree is not a valid BST") << endl;

    cout<< isValid(root);

    return 0;
}

// Example input: 10 7 3 9 5 11 14 18 -1
