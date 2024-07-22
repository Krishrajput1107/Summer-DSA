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

Node* buildtree(Node* &root) {  // Accept root by reference
    int data;
    cout << "Enter the data: " << endl;
    cin >> data;
    if (data == -1) {
        return NULL;
    }

    root = new Node(data);
    cout << "Enter the data in left of " << data << endl;
    root->left = buildtree(root->left);

    cout << "Enter the data in right of " << data << endl;
    root->right = buildtree(root->right);

    return root;
}

bool Identical(Node* root1, Node* root2){
    if(root1==NULL && root2==NULL){
        return true;
    }
    if(root1==NULL && root2!=NULL){
        return false;
    }
    if(root1!=NULL && root2==NULL){
        return false;
    }

    bool left=Identical(root1->left,root2->left);
    bool right=Identical(root1->right,root2->right);

    bool value=root1->data == root2->data;

    if (left&&right&&value){
        return true;
    } 
    else{
        return false;
    }

}


int main() {
    Node* root1 = NULL;
    Node* root2=NULL;
    // Example input: 1 3 5 -1 -1 7 -1 -1 11 -1 -1 17 -1 -1
    cout<<"Build tree 1: "<<endl;
    buildtree(root1);
    cout<<"Build tree 2: "<<endl;
    buildtree(root2);
    cout << "Is tree Identical: " << Identical(root1,root2) << endl;

    return 0;
}
