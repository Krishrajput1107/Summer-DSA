#include <iostream>
#include <queue>
#include <limits.h> // Include for INT_MIN and INT_MAX
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

class info {
public:
    int maxi;
    int mini;
    bool isBST;
    int size;

    // Default constructor
    info() : maxi(INT_MIN), mini(INT_MAX), isBST(true), size(0) {}
};

info solve(Node* root, int& ans) {
    // Base case
    if (root == NULL) {
        return info();
    }

    info left = solve(root->left, ans);
    info right = solve(root->right, ans);

    info currNode;
    currNode.size = left.size + right.size + 1;
    currNode.maxi = max(root->data, right.maxi);
    currNode.mini = min(root->data, left.mini);

    if (left.isBST && right.isBST && (root->data > left.maxi && root->data < right.mini)) {
        currNode.isBST = true;
    } else {
        currNode.isBST = false;
    }

    // Update answer
    if (currNode.isBST) {
        ans = max(ans, currNode.size);
    }

    return currNode;
}

int largestBST(Node* root) {
    int maxSize = 0;
    solve(root, maxSize);
    return maxSize;
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

Node* buildBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = buildBST(root->left, data);
    } else {
        root->right = buildBST(root->right, data);
    }

    return root;
}

void takeinput(Node*& root) {  // Pass root by reference
    int data;
    cout << "Enter data: ";
    cin >> data;
    while (data != -1) {
        root = buildBST(root, data);  // Update root
        cin >> data;
    }
}

int main() {
    Node* root = NULL;
    cout << "Enter tree data: " << endl;
    takeinput(root);
    int ans = largestBST(root);
    cout << "Largest BST with size is: " << ans << endl;

    // Example input: 5 2 4 1 3 -1
    return 0;
}
