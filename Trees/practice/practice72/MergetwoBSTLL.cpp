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

// Function to perform level-order traversal
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

// Function to build a BST
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

// Function to take input for the BST
void takeinput(Node*& root) {
    int data;
    cout << "Enter data (-1 to stop): ";
    cin >> data;
    while (data != -1) {
        root = buildBST(root, data);
        cin >> data;
    }
}

// Function to count nodes in the list
int countnodes(Node* head) {
    int cnt = 0;
    Node* temp = head;
    while (temp != NULL) {
        cnt++;
        temp = temp->right;
    }
    return cnt;
}

// Helper function to convert a BST into a sorted DLL
void ConvertintoSortedDLL(Node* root, Node*& head) {
    if (root == NULL) {
        return;
    }
    // Convert the right subtree and link it to head
    ConvertintoSortedDLL(root->right, head);
    root->right = head;
    if (head != NULL) {
        head->left = root;
    }
    // Move the head to the current root
    head = root;
    // Convert the left subtree
    ConvertintoSortedDLL(root->left, head);
}

// Function to merge two sorted DLLs
Node* mergeLL(Node* head1, Node* head2) {
    if (head1 == NULL) return head2;
    if (head2 == NULL) return head1;

    Node* head = NULL;
    Node* tail = NULL;

    if (head1->data < head2->data) {
        head = tail = head1;
        head1 = head1->right;
    } else {
        head = tail = head2;
        head2 = head2->right;
    }

    while (head1 != NULL && head2 != NULL) {
        if (head1->data < head2->data) {
            tail->right = head1;
            head1->left = tail;
            tail = head1;
            head1 = head1->right;
        } else {
            tail->right = head2;
            head2->left = tail;
            tail = head2;
            head2 = head2->right;
        }
    }

    while (head1 != NULL) {
        tail->right = head1;
        head1->left = tail;
        tail = head1;
        head1 = head1->right;
    }

    while (head2 != NULL) {
        tail->right = head2;
        head2->left = tail;
        tail = head2;
        head2 = head2->right;
    }

    return head;
}

// Helper function to convert sorted DLL to BST
Node* SortedLLtoBST(Node*& head, int n) {
    if (n <= 0 || head == NULL) {
        return NULL;
    }

    // Recursively build the left subtree
    Node* left = SortedLLtoBST(head, n / 2);

    // The current node is the root
    Node* root = head;
    root->left = left;

    // Move to the next node in the DLL
    head = head->right;

    // Recursively build the right subtree
    root->right = SortedLLtoBST(head, n - n / 2 - 1);

    return root;
}

// Helper function to perform inorder traversal (for verification)
void inorder(Node* root) {
    if (root == NULL) {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
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
    cout << "Level-wise Traversal of Merged BST is: " << endl;
    levelwise(mergedBST);

    // Verify the BST using inorder traversal
    cout << "\nInorder Traversal of Merged BST is: " << endl;
    inorder(mergedBST);

    return 0;
}
