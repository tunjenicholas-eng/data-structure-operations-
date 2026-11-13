#include <iostream>
using namespace std;
#define MAX 5

class Queue {
private:
    int front, rear;
    int arr[MAX];

public:
    Queue() { front = -1; rear = -1; }

    // 1. isEmpty
    bool isEmpty() { return front == -1 || front > rear; }
    
    // 2. isFull
    bool isFull() { return rear == MAX - 1; }

    // 3. Enqueue
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is Full!" << endl;
        } else {
            if (front == -1) front = 0;
            rear++;
            arr[rear] = value;
            cout << value << " enqueued." << endl;
        }
    }

    // 4. Dequeue
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is Empty!" << endl;
        } else {
            cout << arr[front] << " dequeued." << endl;
            front++;
        }
    }

    // 5. PeekFront
    void peekFront() {
        if (isEmpty()) {
            cout << "Queue is Empty." << endl;
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    Queue q;
    q.enqueue(10); 
    q.enqueue(20);
    q.peekFront();
    cout << "Is queue full? " << (q.isFull() ? "Yes" : "No") << endl;
    q.dequeue();
    q.peekFront();
    return 0;
}