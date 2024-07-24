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

Node* solve(Node* root, int node, int &k){

    if(root==NULL){
        return NULL;
    }
    if(root->data==node){
        return root;
    }

    Node* leftAns=solve(root->left,node,k);
    Node* rightAns=solve(root->right,node,k);

    if(leftAns!=NULL && rightAns==NULL){
        k--;
        if(k<=0){
            k=INT16_MAX;
            return root;
        }
        return leftAns;
    }

    if(leftAns==NULL && rightAns!=NULL){
        k--;
        if(k<=0){
            k=INT16_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
    
}

int KthAncestor(Node* root,int node,int k){
    Node* ans=solve(root,node,k);
    if(ans==NULL){
        return -1;
    }
    else{
        return ans->data;
    }
}

int main() {
    Node* root = NULL;
    int n=4;
    int k=2;
    root = buildtree();

    int ans = KthAncestor(root,n,k);

    cout << "Kth ancestor of "<< n<<" is: " << ans << endl;

    return 0;
}



// 1 2 4 -1 -1 5 -1 -1 3 -1 -1