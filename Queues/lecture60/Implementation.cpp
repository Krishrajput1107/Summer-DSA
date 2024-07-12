#include <iostream>
using namespace std;

class Queue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    Queue() {
        size = 100;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    // Push operation
    void enqueue(int element) {
        if (rear == size) {
            cout << "Queue is full" << endl;
        } else {
            arr[rear] = element;
            rear++;
        }
    }

    // Pop operation
    int dequeue() {
        if (rear == front) {
            cout << "Queue is empty" << endl;
            return -1;
        } else {
            int ans = arr[front];
            arr[front] = -1;
            front++;
            if (front == rear) {
                front = 0;
                rear = 0;
            }
            return ans;
        }
    }

    // Get front element
    int getFront() {
        if (rear == front) {
            return -1;
        } else {
            return arr[front];
        }
    }

    // Check if the queue is empty
    bool isEmpty() {
        return rear == front;
    }
};

int main() {
    Queue q;

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    // Display front element
    cout << "Front element: " << q.getFront() << endl;  // Output: 10

    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl;  // Output: 10
    cout << "Dequeued: " << q.dequeue() << endl;  // Output: 20

    // Display front element again
    cout << "Front element: " << q.getFront() << endl;  // Output: 30

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;  // Output: No

    // Dequeue remaining element
    cout << "Dequeued: " << q.dequeue() << endl;  // Output: 30

    // Check if the queue is empty again
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;  // Output: Yes

    return 0;
}
