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
Node* minVal(Node* root){
    Node *temp=root;
    while(temp->left!=NULL){
        temp=temp->left;
    }
    return temp;
}

Node* deletion(Node* root, int key){
    
    if(root==NULL){
        return NULL;
    }

    if(root->data==key){
        // 0 child
        if(root->left==NULL && root->right==NULL){
            delete root;
            return NULL;
        }

        // 1 child
        else if(root->left!=NULL && root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }
        else if(root->left==NULL && root->right!=NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }

        //2 child
        else{
            int mini=minVal(root->right)->data;
            root->data=mini;
            root->right=deletion(root->right, mini);
            return root;
        }
    }

    else if(root->data>key){
        root->left=deletion(root->left,key);
    }

    else{
        root->right=deletion(root->right,key);
    }

}

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

int main() {
    Node* root = NULL;
    takeInput(root);

    levelwise(root);
    int key;
    cout<<"Enter the key to be deleted: "<<endl;
    cin>>key;

    deletion(root,key);
    levelwise(root);

    return 0;
}

// Example input: 10 8 21 7 27 5 4 3 -1
