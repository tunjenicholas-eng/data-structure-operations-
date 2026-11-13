#include <iostream>
using namespace std;
#define MAX 5

class Stack {
private:
    int top;
    int arr[MAX];

public:
    Stack() { top = -1; }

    // 1. isEmpty
    bool isEmpty() { return top < 0; }
    
    // 2. isFull
    bool isFull() { return top >= MAX - 1; }

    // 3. Push
    void push(int value) {
        if (isFull()) {
            cout << "Stack Overflow!" << endl;
        } else {
            top++;
            arr[top] = value;
            cout << value << " pushed into stack." << endl;
        }
    }

    // 4. Pop
    void pop() {
        if (isEmpty()) {
            cout << "Stack Underflow!" << endl;
        } else {
            cout << arr[top] << " popped from stack." << endl;
            top--;
        }
    }

    // 5. Peek
    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
        } else {
            cout << "Top element is: " << arr[top] << endl;
        }
    }
};

int main() {
    Stack s;
    s.push(10); 
    s.push(20);
    s.peek();
    cout << "Is stack empty? " << (s.isEmpty() ? "Yes" : "No") << endl;
    s.pop();
    s.peek();
    return 0;
}