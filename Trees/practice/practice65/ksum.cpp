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

int Ksum(Node* root,int k){
    vector<int> path
}

int main() {
    Node* root = NULL;
    int k=5;
    root = buildtree();

    int ans = Ksum(root,k);

    cout << "Number of path which have their sum equal to "<< k<<" is: " << ans << endl;

    return 0;
}



// 1 3 2 -1 -1 1 1 -1 -1 -1 0 4 1 -1 -1 2 -1 -1 5 -1 6 -1 -1