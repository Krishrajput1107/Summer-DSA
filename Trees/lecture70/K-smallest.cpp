#include <iostream>
#include <queue>
#include <climits>  // For INT_MIN and INT_MAX
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

void levelwise(Node* root) {
    if (root == NULL) {
        return;
    }
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        Node* temp = q.front();
        q.pop();
        if (temp == NULL) {
            // Current level has been completely traversed
            cout << endl;
            if (!q.empty()) {
                // Queue still has some child nodes
                q.push(NULL);
            }
        } else {
            cout << temp->data << " ";
            if (temp->left) {
                q.push(temp->left);
            }
            if (temp->right) {
                q.push(temp->right);
            }
        }
    }
}

Node* InsertInBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = InsertInBST(root->left, data);
    } else {
        root->right = InsertInBST(root->right, data);
    }
    return root;
}

void takeInput(Node*& root) {
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    while (data != -1) {
        root = InsertInBST(root, data);
        cin >> data;
    }
}

int solve(Node* root, int &i, int k){
    if(root==NULL){
        return -1;
    }
    int left=solve(root->left,i,k);

    //doubt
    if(left!=-1){
        return left;
    }
    i++;
    if(i==k){
        return root->data;
    }

    int right=solve(root->right,i,k);
    return right;
}

int KthSmallest(Node* root,int k){
    int i=0;
    int ans=solve(root,i,k);
    return ans;
}

int main() {
    Node* root = NULL;
    takeInput(root);

    levelwise(root);
    int k;
    cout<<"enter k: "<<endl;
    cin>>k;

    cout<<"Kth Smallest element in BST is: "<<KthSmallest(root,k)<<endl;

    return 0;
}

// Example input: 10 7 3 9 5 11 14 18 -1
