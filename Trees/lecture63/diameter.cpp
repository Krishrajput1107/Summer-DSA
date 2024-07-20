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

    return max(left, right) + 1;
}
pair<int,int> diameterFast(Node* root) {
        //base case
        if(root == NULL) {
            pair<int,int> p = make_pair(0,0);
            return p;
        }
        
        pair<int,int> left = diameterFast(root->left);
        pair<int,int> right = diameterFast(root->right);
        
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second + 1;
        
        pair<int,int> ans;
        ans.first = max(op1, max(op2, op3));;
        ans.second = max(left.second , right.second) + 1;

        return ans;
    }
    //this
int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int opt1 = diameter(root->left);
    int opt2 = diameter(root->right);
    int opt3 = height(root->left) + 1 + height(root->right);

    return max(opt3, max(opt1, opt2));
}

int main() {
    Node* root = NULL;
    // Example input: 1 3 5 -1 -1 7 -1 -1 11 -1 -1 17 -1 -1
    buildtree(root);
    cout << "Height of tree is: " << height(root) << endl;
    cout << "Diameter of tree is: " << diameter(root) << endl;  

    return 0;
}
//jhgfdsxcvbn