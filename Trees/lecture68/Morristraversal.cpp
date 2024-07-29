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

void MorrisTraversal(Node* root){

    Node* current=root;
    while(current!=NULL){
        if(current->left==NULL){
            cout<< current->data<<" ";
            current=current->right;
        }
        else{
            Node* pred=current->left;
            while(pred->right !=NULL && pred->right!=current){
                pred=pred->right;
            }

            if(pred->right==NULL){
                pred->right=current;
                current=current->left;
            }

            else{
                pred->right=NULL;
                cout<< current->data<<" ";
                current=current->right;
            }
        }
    }
}
int main() {
    Node* root = buildtree(); // Assign the returned root node to 'root'
    cout << "Morris Traversal: ";
    MorrisTraversal(root);

    return 0;
}
// Example input: 1 2 4 -1 7 -1 -1 5 -1 -1 3 -1 6 -1 -1

