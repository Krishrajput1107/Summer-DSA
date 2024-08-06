#include <iostream>
#include <stack>
#include <queue>
#include <map>
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

int findPosition(int in[], int element, int size) {
    for (int i = 0; i < size; i++) {
        if (in[i] == element) {
            return i;
        }
    }
    return -1;
}

Node* solve(int in[], int post[], int &index, int inorderStart, int inorderEnd, int size) {
    if (index < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = post[index--];
    Node* root = new Node(element);
    int pos = findPosition(in, element, size);

    
    root->right = solve(in, post, index, pos + 1, inorderEnd, size);
    root->left = solve(in, post, index, inorderStart, pos - 1, size);

    return root;
}

Node* buildTree(int in[], int post[], int n) {
    int postorderIndex = n-1;
    Node* ans = solve(in, post, postorderIndex, 0, n - 1, n);
    return ans;
}

void preOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    cout << root->data << " ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

int main() {
    int in[] = {4,8,2,5,1,6,3,7};
    int post[] = {8,4,5,2,6,7,3,1};
    int n = 8;
    Node* ans = buildTree(in, post, n);

    preOrderTraversal(ans);

    return 0;
}
