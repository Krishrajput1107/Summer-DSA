#include <iostream>
#include <queue>
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

Node* buildBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left = buildBST(root->left, data);
    } else {
        root->right = buildBST(root->right, data);
    }

    return root;
}

void takeinput(Node*& root) {  // Pass root by reference
    int data;
    cout << "Enter data: ";
    cin >> data;
    while (data != -1) {
        root = buildBST(root, data);  // Update root
        cin >> data;
    }
}

void InOrder(Node* root, vector<int> &in){
    if(root==NULL){
        return;
    }
    InOrder(root->left,in);
    in.push_back(root->data);
    InOrder(root->right,in);
}

vector<int> Mergevector(vector<int> a,vector<int> b){
    int i=0,j=0,k=0;
    vector<int> ans(a.size()+b.size());
    while(i<a.size() && j<b.size()){
        if(a[i]<b[j]){
            ans[k++]=a[i];
            i++;
        }
        else{
            ans[k++]=b[j];
            j++;
        }
    }
    while(i<a.size()){
        ans[k++]=a[i];
        i++;
    }
    while(j<b.size()){
        ans[k++]=b[j];
        j++;
    }

    return ans;
}

Node* NormaltoBST(vector<int> ans,int s, int e){
    if(s>e){
        return NULL;
    }
    int mid=(s+e)/2;
    Node *root=new Node(ans[mid]);
    root->left=NormaltoBST(ans,s,mid-1);
    root->right=NormaltoBST(ans,mid+1,e);

    return root;
}

Node* mergeBST(Node* root1,Node* root2){
    vector<int> bst1;
    vector<int> bst2;
    InOrder(root1,bst1);
    InOrder(root2,bst2);

    vector<int>ans=Mergevector(bst1,bst2);

    int size=ans.size();
    int s=0,e=size-1;

    Node* root=NormaltoBST(ans,s,e);

    return root;

}

int main() {
    Node* root1 = NULL;
    Node* root2=NULL;
    cout<<"Enter tree 1 data: "<<endl;
    takeinput(root1);
    cout<<"Enter tree 2 data: "<<endl;
    takeinput(root2);

    Node*ans =mergeBST(root1,root2);

    cout<<"Level wise Traversal of MErged BST is: "<<endl;
    levelwise(ans);

    

    return 0;
}
