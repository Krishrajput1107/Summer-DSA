#include <iostream>
#include <queue>
#include <stack>
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

Node* buildtree() {
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;

    if (data == -1) {
        return NULL;
    }

    Node* root = new Node(data);

    cout << "Enter data in left of " << data << endl;
    root->left = buildtree();

    cout << "Enter data in right of " << data << endl;
    root->right = buildtree();

    return root;
}

// Helper function to find the k-th ancestor
Node* solve(Node* root, int n, int &k) {
    if (root == NULL) {
        return NULL;
    }

    if (root->data == n) {
        return root;
    }

    Node* leftAns = solve(root->left, n, k);
    Node* rightAns = solve(root->right, n, k);

    if (leftAns != NULL && rightAns == NULL) {
        k--;
        if (k <= 0) {
            k = INT16_MAX; // Prevent further decrement in the stack
            return root;
        }
        return leftAns;
    }

    if (leftAns == NULL && rightAns != NULL) {
        k--;
        if (k <= 0) {
            k = INT16_MAX; // Prevent further decrement in the stack
            return root;
        }
        return rightAns;
    }

    return NULL; // If both leftAns and rightAns are NULL, return NULL
}

// Function to find the k-th ancestor of a node with value n
int KthAncestor(Node* root, int n, int k) {
    Node* ans = solve(root, n, k);

    if (ans == NULL || ans->data == n) { 
        return -1; // If ans is null or ans is the node itself, no ancestor exists
    } else {
        return ans->data;
    }
}

int main() {
    Node* root = NULL;
    int n=4;
    int k=1;
    root = buildtree();

    int ans = KthAncestor(root,n,k);

    cout << "Kth ancestor of "<< n<<" is: " << ans << endl;

    return 0;
}



// 1 2 4 -1 -1 5 -1 -1 3 -1 -1