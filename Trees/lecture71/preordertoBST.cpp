#include <iostream>
#include <queue>
#include<vector>
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

Node* solve(vector<int> &preorder,int mini,int maxi,int &i){

    if(i>preorder.size()){
        return NULL;
    }

    if(preorder[i]<mini || preorder[i]>maxi){
        return NULL;
    }

    Node* root=new Node(preorder[i++]);
    root->left=solve(preorder,mini,root->data,i);
    root->right=solve(preorder,root->data,maxi,i);

    return root;

}

Node* preordertoBST(Node* root,vector<int> &p){

   int mini=INT16_MIN;
   int maxi=INT16_MAX;
   int i=0;

   return solve(p,mini,maxi,i);

}

int main() {
    Node* root=NULL;

    vector<int> p={20,10,5,15,13,35,30,42};

    Node* ans=preordertoBST(root,p);

    levelwise(ans);

    


    return 0;
}

