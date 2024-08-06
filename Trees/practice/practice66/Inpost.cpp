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

Node* solve(int in[], int pre[], int &index, int inorderStart, int inorderEnd, int size) {
    if (index >= size || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = pre[index++];
    Node* root = new Node(element);
    int pos = findPosition(in, element, size);

    root->left = solve(in, pre, index, inorderStart, pos - 1, size);
    root->right = solve(in, pre, index, pos + 1, inorderEnd, size);

    return root;
}

Node* buildTree(int in[], int pre[], int n) {
    int preorderIndex = 0;
    Node* ans = solve(in, pre, preorderIndex, 0, n - 1, n);
    return ans;
}

void postOrderTraversal(Node* root) {
    if (root == NULL) {
        return;
    }
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout << root->data << " ";
}

int main() {
    int in[] = {3, 1, 4, 0, 5, 2};
    int pre[] = {0, 1, 3, 4, 2, 5};
    int n = 6;
    Node* ans = buildTree(in, pre, n);

    postOrderTraversal(ans);

    return 0;
}
