#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class MyQueue {
private:
    int arr[MAX_SIZE];
    int front, rear, size;

public:
    MyQueue() {
        front = -1;
        rear = -1;
        size = 0;
    }

    bool isEmpty() {
        return size == 0;
    }

    bool isFull() {
        return size == MAX_SIZE;
    }

    void enqueue(int val) {
        if (isFull()) {
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % MAX_SIZE;
        arr[rear] = val;
        size++;
    }

    int dequeue() {
        if (isEmpty()) {
            return -1;
        }
        int val = arr[front];
        front = (front + 1) % MAX_SIZE;
        size--;
        if (isEmpty()) {
            front = -1;
            rear = -1;
        }
        return val;
    }
    
    int getSize() {
        return size;
    }
};

class StackUsingOneQueue {
private:
    MyQueue q;

public:
    void push(int val) {
        q.enqueue(val);
        int currentSize = q.getSize();
        for (int i = 0; i < currentSize - 1; i++) {
            q.enqueue(q.dequeue());
        }
        cout << val << " pushed to the stack." << endl;
    }

    void pop() {
        if (q.isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        int val = q.dequeue();
        cout << val << " popped from the stack." << endl;
    }

    bool isEmpty() {
        return q.isEmpty();
    }
};

int main() {
    StackUsingOneQueue s;
    s.push(10);
    s.push(20);
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
