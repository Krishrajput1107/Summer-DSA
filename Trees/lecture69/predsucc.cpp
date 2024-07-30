#include <iostream>
#include <queue>
using namespace std;

class Node {
public:
    int data;
    Node* left;
    Node* right;

    Node(int d) {
        this->data = d;  // Corrected this line to assign 'd' directly
        this->left = NULL;
        this->right = NULL;
    }
};



Node* InsertInBST(Node* root, int data) {
    if (root == NULL) {
        root = new Node(data);
        return root;
    }

    if (data < root->data) {
        root->left=InsertInBST(root->left, data);
    } else {
        root->right=InsertInBST(root->right, data);
    }
    return root;

    
}

void takeInput(Node*& root) {  // Modified to take Node*& to modify the original root
    cout << "Enter the data: " << endl;
    int data;
    cin >> data;
    while (data != -1) {
        root = InsertInBST(root, data);  // Modified to update the original root
        cin >> data;
    }
}

void findPredSuc(Node* root,int key, Node* &pred, Node* & succ){
    if(root==NULL){
        return;
    }
    if(root->data==key){
        if(root->left!=NULL){
            Node* temp=root->left;
            while(temp->right!=NULL)
                temp=temp->right;
            pred=temp;
        }
        if(root->right!=NULL){
            Node *temp=root->right;
            while(temp->left!=NULL)
                temp=temp->left;
            succ=temp;
        }
        return;
    }
    if(root->data>key){
        succ=root;// This root could be the successor
        findPredSuc(root->left,key,pred,succ);
    }
    else{
        pred=root;// This root could be the predecessor
        findPredSuc(root->right,key,pred,succ);
    }

}

int main() {
    Node* pred=NULL;
    Node* succ=NULL;
    Node* root = NULL;
    takeInput(root);
    int key;
    cout<<"Enter key: "<<endl;
    cin>>key;
    findPredSuc(root,key,pred,succ);

    cout<<"Predecessor of "<<key<<" is "<<pred->data<<endl;
    cout<<"Successor of "<<key<<" is "<<succ->data<<endl;
    return 0;
}

// Example input: 10 8 21 7 27 5 4 3 -1
