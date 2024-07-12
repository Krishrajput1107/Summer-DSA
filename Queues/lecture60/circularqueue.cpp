#include <iostream>
using namespace std;

class CircularQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    CircularQueue(int size = 100) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    // Enqueue operation
    void enqueue(int element) {
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full" << endl;
            return;
        }

        // First element to be inserted
        if (front == -1) {
            front = rear = 0;
            arr[rear] = element;
        }
        // Rear is at the end of the array, wrap around
        else if (rear == size - 1 && front != 0) {
            rear = 0;
            arr[rear] = element;
        } 
        // Normal case
        else {
            rear++;
            arr[rear] = element;
        }
    }

    // Dequeue operation
    int dequeue() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[front];
        arr[front] = -1;  // Optional: clear the slot

        // Single element case
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        // Front at the end, wrap around
        else if (front == size - 1) {
            front = 0;
        }
        // Normal case
        else {
            front++;
        }
        return ans;
    }

    // Get front element
    int getFront() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[front];
    }

    // Get rear element
    int getRear() {
        if (rear == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }
        return arr[rear];
    }

    // Check if the queue is empty
    bool isEmpty() {
        return front == -1;
    }

    // Destructor to free allocated memory
    ~CircularQueue() {
        delete[] arr;
    }
};

int main() {
    CircularQueue q(5);  // Creating a circular queue of size 5

    // Enqueue elements
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);

    // Trying to enqueue when queue is full
    q.enqueue(60);

    // Display front element
    cout << "Front element: " << q.getFront() << endl;  // Output: 10

    // Dequeue elements
    cout << "Dequeued: " << q.dequeue() << endl;  // Output: 10
    cout << "Dequeued: " << q.dequeue() << endl;  // Output: 20

    // Display front element again
    cout << "Front element: " << q.getFront() << endl;  // Output: 30

    // Enqueue more elements
    q.enqueue(60);
    q.enqueue(70);

    // Display front element
    cout << "Front element: " << q.getFront() << endl;

    // Display rear element
    cout << "Rear element: " << q.getRear() << endl;  // Output: 70

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;  // Output: No

    // Dequeue all elements
    while (!q.isEmpty()) {
        cout << "Dequeued: " << q.dequeue() << endl;
    }

    // Check if the queue is empty again
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;  // Output: Yes

    return 0;
}
