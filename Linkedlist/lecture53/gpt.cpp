#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }

    // Destructor
    ~Node() {
        int value = this->data;
        // MEMORY FREE
        if (this->next != NULL) {
            delete next;
            this->next = NULL;
        }
        cout << "Memory is free for node with data " << value << endl;
    }
};

void InsertatHead(Node*& head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void InsertatTail(Node*& tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void print(Node*& head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void InsertAtPosition(Node*& tail, Node*& head, int position, int d) {
    // Insert at start position
    if (position == 1) {
        InsertatHead(head, d);
        return;
    }
    int cnt = 1;
    Node* temp = head;
    while (cnt < position - 1) {
        temp = temp->next;
        cnt++;
    }
    // Insert at last position
    if (temp->next == NULL) {
        InsertatTail(tail, d);
        return;
    }

    // Insert at any position
    Node* nodetoInsert = new Node(d);
    nodetoInsert->next = temp->next;
    temp->next = nodetoInsert;
}

void deleteNode(int position, Node*& head) {
    // Deleting first node
    if (position == 1) {
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }
    // Deleting any mid or last node
    else {
        Node* current = head;
        Node* prev = NULL;
        int cnt = 1;
        while (cnt < position) {
            prev = current;
            current = current->next;
            cnt++;
        }
        prev->next = current->next;
        current->next = NULL;
        delete current;
    }
}

Node* findmid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {
    if (left == NULL) {
        return right;
    }
    if (right == NULL) {
        return left;
    }
    Node* ans = new Node(-1);
    Node* temp = ans;

    while (left != NULL && right != NULL) {
        if (left->data < right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        } else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while (left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while (right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next;
    }
    Node* result = ans->next;
    delete ans; // Deleting dummy node
    return result;
}

Node* mergeSort(Node* head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    // Create right and left halves
    Node* mid = findmid(head);
    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    // Recursive calls to sort both halves
    left = mergeSort(left);
    right = mergeSort(right);

    // Merge both halves
    Node* result = merge(left, right);
    return result;
}

int main() {
    // Created a new node
    Node* node1 = new Node(5);

    // Head pointed to node 1
    Node* head = node1;
    Node* tail = node1;
    print(head);
    InsertatTail(tail, 12);
    print(head);

    InsertatTail(tail, 15);
    print(head);

    InsertatTail(tail, 11);
    print(head);

    InsertatTail(tail, 3);
    print(head);

    InsertatTail(tail, 7);
    print(head);

    InsertatTail(tail, 1);
    print(head);

    Node* answer = mergeSort(head);
    print(answer);

    return 0;
}
