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
    Node* curr=root;
    while(curr!=NULL){
        if(curr->left==NULL){
            cout<<curr->data<<" ";
            curr=curr->right;
        }
        else{
            Node* pred=curr->left;
            while(pred->right!=NULL && pred->right!=curr){
                pred=pred->right;
            }
            if(pred->right==NULL){
                    pred->right=curr;
                    curr=curr->left;
                }
            else{
                pred->right=NULL;
                cout<<curr->data<<" ";
                curr=curr->right;
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

