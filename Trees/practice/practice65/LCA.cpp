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



Node* LCA(Node* root,int n1,int n2){
    if(root==NULL){
        return NULL;
    }
    if(root->data==n1 || root->data==n2){
        return root;
    }
    Node* leftAns= LCA(root->left,n1,n2);
    Node* rightAns=LCA(root->right,n1,n2);

    if(leftAns!=NULL && rightAns!=NULL){
        return root;
    }
    else if(leftAns!=NULL && rightAns==NULL){
        return leftAns;
    }
    else if(leftAns==NULL && rightAns!=NULL){
        return rightAns;
    }
    else{
        return NULL;
    }
}


int main() {
    Node* root = NULL;
    int n1=4;
    int n2=21;
    root = buildtree();

    Node* ans = LCA(root,n1,n2);

    cout << "Lowest common ancestor is: " << ans->data << endl;

    return 0;
}



// 1 2 6 -1 8 -1 -1 -1 3 4 -1 -1 5 21 -1 -1 -1 