#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;  // Corrected this line to assign 'd' directly
        this->left = NULL;
        this->right = NULL;
    }
};



Node* InsertInBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left=InsertInBST(root->left, data);
    } else {
        root->right=InsertInBST(root->right, data);
    }

    
}

void takeInput(Node*& root) {  // Modified to take Node*& to modify the original root
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    while (data != -1) {
        root = InsertInBST(root, data);  // Modified to update the original root
        cin >> data;
    }
}

int main() {
    Node* root = NULL;
    takeInput(root);


    return 0;
}

// Example input: 10 8 21 7 27 5 4 3 -1
