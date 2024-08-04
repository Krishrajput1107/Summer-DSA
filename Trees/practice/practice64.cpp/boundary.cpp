#include <iostream>
#include <vector>
#include <queue>
#include <stack>
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

void leftTraversal(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    ans.push_back(root->data);
    if (root->left) {
        leftTraversal(root->left, ans);
    } else {
        leftTraversal(root->right, ans);
    }
}

void leafTraversal(Node* root, vector<int>& ans) {
    if (root == NULL) {
        return;
    }
    if (root->left == NULL && root->right == NULL) {
        ans.push_back(root->data);
        return;
    }
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);
}

void rightTraversal(Node* root, vector<int>& ans) {
    if (root == NULL || (root->left == NULL && root->right == NULL)) {
        return;
    }
    if (root->right) {
        rightTraversal(root->right, ans);
    } else {
        rightTraversal(root->left, ans);
    }
    ans.push_back(root->data); // Add after recursive call to reverse order
}

vector<int> Boundary(Node* root) {
    vector<int> ans;
    if (root == NULL) {
        return ans;
    }
    ans.push_back(root->data);

    // Traverse left boundary excluding leaf nodes
    leftTraversal(root->left, ans);

    // Traverse leaf nodes
    leafTraversal(root->left, ans);
    leafTraversal(root->right, ans);

    // Traverse right boundary excluding leaf nodes
    vector<int> rightNodes;
    rightTraversal(root->right, rightNodes);
    ans.insert(ans.end(), rightNodes.begin(), rightNodes.end());

    return ans;
}

Node* buildtree(Node*& root) {
    int data;
    cout << "Enter the data: ";
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    root = new Node(data);

    cout << "Insert data inserting at left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "Insert data inserting at right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

int main() {
    Node* root = NULL;
    // Example input: 1 2 3 -1 -1 5 6 -1 -1 8 -1 -1 4 -1 7 -1 9 10 -1 -1 11 -1 -1
    buildtree(root);

    vector<int> answer = Boundary(root);
    cout << "Printing boundary order traversal: ";

    for (int i = 0; i < answer.size(); i++) {
        cout << answer[i] << " ";
    }
    cout << endl;

    return 0;
}
