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

pair<bool,int> SumTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }
    if(root->left==NULL && root->right==NULL){
        pair<bool,int> p=make_pair(true,root->data);
        return p;
    }
    pair<bool,int> leftAns=SumTreeFast(root->left);
    pair<bool,int> rightAns=SumTreeFast(root->right);

    bool isleft=leftAns.first;
    bool isright=rightAns.first;

    bool condn= root->data==leftAns.second+rightAns.second;

    pair<bool,int> ans;
    if(isleft && isright && condn){
        ans.first=true;
        ans.second=2*root->data;
    }
    else{
        ans.first=false;
    }
    return ans;
}

int main() {
    Node* root = NULL;
    // Example input: 1 3 5 -1 -1 7 -1 -1 11 -1 -1 17 -1 -1
    root = buildtree(root);

    pair<bool, int> result = SumTreeFast(root);
    if (result.first) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
