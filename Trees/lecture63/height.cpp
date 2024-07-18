#include<iostream>
#include<stack>
#include<queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int data) {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildtree(Node* &root) {  // Accept root by reference
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    root = new Node(data);
    cout << "Enter the data in left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "Enter the data in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

int main() {
    Node* root = NULL;
    // Example input: 1 3 5 -1 -1 7 -1 -1 11 -1 -1 17 -1 -1
    buildtree(root);
    cout << "Height of tree is: " << height(root) << endl;

    return 0;
}
