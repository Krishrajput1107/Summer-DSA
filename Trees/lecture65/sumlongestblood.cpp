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

void solve(Node* root, int len, int& maxlen, int sum, int& maxsum) {
    if (root == NULL) {
        if (len > maxlen) {
            maxlen = len;
            maxsum = sum;
        }
        else if (len == maxlen) {
            maxsum = max(sum, maxsum);
        }
        return;
    }

    sum = sum + root->data;
    solve(root->left, len + 1, maxlen, sum, maxsum);
    solve(root->right, len + 1, maxlen, sum, maxsum);
}

int Sumlongestblood(Node* root) {
    int len = 0;
    int maxlen = 0;
    int sum = 0;
    int maxsum = INT16_MIN;

    solve(root, len, maxlen, sum, maxsum);

    return maxsum;
}

int main() {
    Node* root = NULL;
    root = buildtree();

    int ans = Sumlongestblood(root);

    cout << "Sum of longest path is: " << ans << endl;

    return 0;
}



// 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1