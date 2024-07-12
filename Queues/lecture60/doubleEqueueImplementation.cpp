#include <iostream>
using namespace std;

class DoubleendedQueue {
public:
    int *arr;
    int front;
    int rear;
    int size;

    DoubleendedQueue(int size = 100) {
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushfront(int element) {
        // Queue is full condition
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full " << endl;
            return;
        }
        // First element to be inserted
        else if (front == -1) {
            front = rear = 0;
            arr[front] = element;
        }
        // Front is at the start of the array, wrap around
        else if (front == 0 && rear != size - 1) {
            front = size - 1;
            arr[front] = element;
        }
        // Normal case
        else {
            front--;
            arr[front] = element;
        }
    }

    // Push back
    void pushrear(int element) {
        // Queue is full condition
        if ((front == 0 && rear == size - 1) || (rear == (front - 1) % (size - 1))) {
            cout << "Queue is full" << endl;
            return;
        }
        // First element to be inserted
        else if (front == -1) {
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

    // Pop front
    int popfront() {
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

    // Pop back
    int poprear() {
        if (front == -1) {
            cout << "Queue is empty" << endl;
            return -1;
        }

        int ans = arr[rear];
        arr[rear] = -1;  // Optional: clear the slot

        // Single element case
        if (front == rear) {
            front = -1;
            rear = -1;
        }
        // Rear at the start, wrap around
        else if (rear == 0) {
            rear = size - 1;
        }
        // Normal case
        else {
            rear--;
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
    ~DoubleendedQueue() {
        delete[] arr;
    }
};

int main() {
    DoubleendedQueue q(5);  // Creating a double-ended queue of size 5

    // Enqueue elements
    q.pushrear(10);
    q.pushrear(20);
    q.pushrear(30);

    // Trying to enqueue when queue is full
    q.pushrear(40);
    q.pushrear(50);
    q.pushrear(60);  // This should print "Queue is full"

    // Display front and rear elements
    cout << "Front element: " << q.getFront() << endl;  // Output: 10
    cout << "Rear element: " << q.getRear() << endl;    // Output: 50

    // Dequeue elements from front
    cout << "Dequeued from front: " << q.popfront() << endl;  // Output: 10
    cout << "Dequeued from front: " << q.popfront() << endl;  // Output: 20

    // Display front element again
    cout << "Front element: " << q.getFront() << endl;  // Output: 30

    // Enqueue more elements
    q.pushrear(60);
    q.pushrear(70);  // This should print "Queue is full"

    // Display front and rear elements
    cout << "Front element: " << q.getFront() << endl;  // Output: 30
    cout << "Rear element: " << q.getRear() << endl;    // Output: 60

    // Dequeue elements from rear
    cout << "Dequeued from rear: " << q.poprear() << endl;  // Output: 60
    cout << "Dequeued from rear: " << q.poprear() << endl;  // Output: 50

    // Check if the queue is empty
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;  // Output: No

    // Dequeue all elements
    while (!q.isEmpty()) {
        cout << "Dequeued from front: " << q.popfront() << endl;
    }

    // Check if the queue is empty again
    cout << "Is the queue empty? " << (q.isEmpty() ? "Yes" : "No") << endl;  // Output: Yes

    return 0;
}
