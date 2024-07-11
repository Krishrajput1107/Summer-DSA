#include <iostream>
#include <stack>
using namespace std;

class Stack {
public:
    int mini;
    stack<int> s;

    // Push in stack
    void push(int data) {
        // First element push
        if (s.empty()) {
            s.push(data);
            mini = data;
        } else {
            if (data < mini) {
                int val = 2 * data - mini;
                s.push(val);
                mini = data;
            } else {
                s.push(data);
            }
        }
    }

    int pop() {
        if (s.empty()) {
            return -1;
        }
        int curr = s.top();
        s.pop();
        if (curr < mini) {
            int prevMin = mini;
            mini = 2 * mini - curr;
            return prevMin;
        } else {
            return curr;
        }
    }

    int top() {
        if (s.empty()) {
            return -1;
        }

        int curr = s.top();
        if (curr < mini) {
            return mini;
        } else {
            return curr;
        }
    }

    bool isEmpty() {
        return s.empty();
    }

    int getMin() {
        if (s.empty()) {
            return -1;
        } else {
            return mini;
        }
    }
};

int main() {
    Stack s;
    s.push(5);
    s.push(3);
    s.push(8);
    s.push(2);
    s.push(4);

    cout << "Minimum element: " << s.getMin() << endl;  

    s.pop();
    cout << "Top element after pop: " << s.top() << endl; 
    cout << "Minimum element after pop: " << s.getMin() << endl;

    s.pop();
    cout << "Top element after pop: " << s.top() << endl; 
    cout << "Minimum element after pop: " << s.getMin() << endl;  

    return 0;
}
