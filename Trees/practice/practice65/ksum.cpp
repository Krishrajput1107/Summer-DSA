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

void solve(Node* root,int k, int &count,vector<int> path){
    if(root==NULL){
        return;
    }
    path.push_back(root->data);
    solve(root->left,k,count,path);
    solve(root->right,k,count,path);

    int size=path.size();
    int sum=0;
    for(int i=size-1;i>=0;i--){
        sum=sum+path[i];
        if(sum==k){
            count++;
        }
    }
    path.pop_back();
}

int Ksum(Node* root,int k){
    vector<int> path;
    int count=0;
    solve(root,k,count,path);

    return count;
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