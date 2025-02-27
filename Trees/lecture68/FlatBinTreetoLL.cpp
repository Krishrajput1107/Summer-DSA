#include <iostream>
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

void FlattenTree(Node* root) {
    Node* current = root;
    while (current != NULL) {
        if (current->left != NULL) {
            Node* pred = current->left;
            while (pred->right != NULL) {
                pred = pred->right;
            }
            pred->right = current->right;
            current->right = current->left;
            current->left = NULL;  // Set current->left to NULL immediately
        }
        current = current->right;
    }
}

void PrintFlattenedTree(Node* root) {
    Node* current = root;
    while (current != NULL) {
        cout << current->data << " ";
        current = current->right;
    }
    cout << endl;
}

int main() {
    Node* root = buildtree(); // Assign the returned root node to 'root'
    cout << "Flatten Tree: ";
    FlattenTree(root);
    PrintFlattenedTree(root); // Print the flattened tree

    return 0;
}

// Example input: 1 2 3 -1 -1 4 -1 -1 5 -1 6 -1 -1
