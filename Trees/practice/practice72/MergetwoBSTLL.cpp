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

int countnodes(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        temp=temp->right;
    }
    return cnt;
}

void ConvertintoSortedDLL(Node* root, Node* head){
    if(root==NULL){
        return;
    }
    ConvertintoSortedDLL(root->right,head);
    root->right=head;
    if(head!=NULL){
        head->left=root;
    }
    head=root;
    ConvertintoSortedDLL(root->left,head);

}

Node* mergeLL(Node* head1,Node* head2){
    Node* head=NULL;
    Node* tail=NULL;

    while(head1!=NULL && head2!=NULL){
        if(head1->data<head2->data){
            if(head==NULL){
                head=head1;
                tail=head1;
                head1=head1->right;
            }
            else{
               tail->right=head1;
               head1->left=tail;
               tail=head1;
               head1=head1->right; 
            }
        }

        else{
            if(head==NULL){
                head=head2;
                tail=head2;
                head2=head2->right;
            }
            else{
                tail->right=head2;
                head2->left=tail;
                tail=head2;
                head2=head2->right;
            }
        }
    }
    while(head1!=NULL){
        tail->right=head1;
        head1->left=tail;
        tail=head1;
        head1=head1->right;
    }
    while(head2!=NULL){
        tail->right=head2;
        head2->left=tail;
        tail=head2;
        head2=head2->right;
    }

    return head;
}


int main() {
    Node* root1 = NULL;
    Node* root2 = NULL;
    cout << "Enter tree 1 data: " << endl;
    takeinput(root1);
    cout << "Enter tree 2 data: " << endl;
    takeinput(root2);

    // Convert the first BST to a sorted DLL
    Node* head1 = NULL;
    ConvertintoSortedDLL(root1, head1);

    // Convert the second BST to a sorted DLL
    Node* head2 = NULL;
    ConvertintoSortedDLL(root2, head2);

    // Merge the two sorted DLLs
    Node* mergedHead = mergeLL(head1, head2);

    // Count the total number of nodes in the merged list
    int totalNodes = countnodes(mergedHead);

    // Convert the merged sorted DLL back to a balanced BST
    Node* mergedBST = SortedLLtoBST(mergedHead, totalNodes);

    // Display the merged BST using level-order traversal
    cout << "Level wise Traversal of Merged BST is: " << endl;
    levelwise(mergedBST);

    return 0;
}
