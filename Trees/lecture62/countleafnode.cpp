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

Node* buildtree(Node* root) {
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

void preOrder(Node* root, int &cnt) {  // Pass cnt by reference
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        cnt++;
    }
    preOrder(root->left, cnt);
    preOrder(root->right, cnt);
}

int main() {
    Node *root = NULL;
    int cnt = 0;
    // Example input: 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    root = buildtree(root);

    preOrder(root, cnt);
    cout << "Number of leaf nodes: " << cnt << endl;

    return 0;
}
