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

int height(Node* root){
    if(root == NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    int ans = max(left, right) + 1;
    return ans;
}

pair<bool,int> balancedTreeFast(Node* root){
    if(root==NULL){
        pair<bool,int> p=make_pair(true,0);
        return p;
    }

    pair<bool,int> left=balancedTreeFast(root->left);
    pair<bool,int> right=balancedTreeFast(root->right);

    bool leftAns=left.first;
    bool rightAns=right.first;

    bool diff=abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second=max(left.second,right.second)+1;
    if(leftAns && rightAns && diff){
        ans.first=true;
    }
    else{
        ans.first= false;
    }
    return ans;
}

bool balancedTree(Node* root){
    if(root==NULL){
        return true;
    }
    bool left=balancedTree(root->left);
    bool right=balancedTree(root->right);

    bool diff=abs(height(root->left)-height(root->right))<=1;

    if(left && right && diff){
        return true;
    }
    else{
        return false;
    }
}
//don
int main() {
    Node* root = NULL;
    // Example input: 1 3 5 -1 -1 7 -1 -1 11 -1 -1 17 -1 -1
    root = buildtree(root);

    pair<bool, int> result = balancedTreeFast(root);
    if (result.first) {
        cout << "The tree is balanced." << endl;
    } else {
        cout << "The tree is not balanced." << endl;
    }

    return 0;
}
