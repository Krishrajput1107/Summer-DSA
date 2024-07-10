#include <iostream>
using namespace std;

// Node class to represent each element in the stack
class Node {
public:
    int data;
    Node* next;

    // Constructor
    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

// Stack class using linked list
class Stack {
public:
    Node* top;

    // Constructor
    Stack() {
        top = NULL;
    }

    // Push operation to insert an element at the top of the stack
    void push(int element) {
        Node* newNode = new Node(element);
        if (top == NULL) {
            top = newNode;
        } else {
            newNode->next = top;
            top = newNode;
        }
        cout << element << " pushed to stack\n";
    }

    // Pop operation to remove the top element from the stack
    void pop() {
        if (top == NULL) {
            cout << "Stack underflow\n";
            return;
        }
        Node* temp = top;
        top = top->next;
        delete temp;
        cout << "Element popped from stack\n";
    }

    // Peek operation to return the top element without removing it
    int peek() {
        if (top == NULL) {
            cout << "Stack is empty\n";
            return -1;
        }
        return top->data;
    }

    // Check if the stack is empty
    bool isEmpty() {
        return top == NULL;
    }

    // Destructor to free all nodes
    ~Stack() {
        while (top != NULL) {
            Node* temp = top;
            top = top->next;
            delete temp;
        }
    }
};

int main() {
    Stack st;

    st.push(1);
    st.push(2);
    st.push(3);

    cout << "Top element is " << st.peek() << endl;

    st.pop();
    cout << "Top element after pop is " << st.peek() << endl;

    cout << (st.isEmpty() ? "Stack is empty" : "Stack is not empty") << endl;

    return 0;
}
