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

int Min(Node* root){
    Node* temp=root;
    while(temp!=NULL && temp->left != NULL){
        temp=temp->left;
    }
    return temp->data;
}

int Max(Node* root){
    Node* temp=root;
    while(temp!=NULL && temp->right != NULL){
        temp=temp->right;
    }
    return temp->data;
}

int main() {
    Node* root = NULL;
    takeInput(root);
    cout<<"Minimum element: "<<Min(root)<<endl;
    cout<<"Maximun element: "<<Max(root)<<endl;
    
    return 0;
}

// Example input: 10 8 21 7 27 5 4 3 -1
