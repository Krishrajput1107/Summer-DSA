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

void solve(Node* root,int sum, int &maxsum, int len, int &maxlen){
    if(root==NULL){
        if(len>maxlen){
            maxlen=len;
            maxsum=sum;
        }
        if(len==maxlen){
            maxsum=max(sum,maxsum);
        }
        return;
    }
    sum=sum+root->data;
    solve(root->left,sum,maxsum,len+1,maxlen);
    solve(root->right,sum,maxsum,len+1,maxlen);
}

int Sumlongestblood(Node* root){
    int sum=0;
    int maxsum=0;

    int len=0;
    int maxlen=0;

    solve(root,sum,maxsum,len,maxlen);
    return maxsum;
}

int main() {
    Node* root = NULL;
    root = buildtree();

    int ans = Sumlongestblood(root);

    cout << "Sum of longest path is: " << ans << endl;

    return 0;
}



// 4 2 7 -1 -1 1 6 -1 -1 -1 5 2 -1 -1 3 -1 -1