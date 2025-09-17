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
};

class StackUsingTwoQueues {
private:
    MyQueue q1, q2;

public:
    void push(int val) {
        q2.enqueue(val);
        while (!q1.isEmpty()) {
            q2.enqueue(q1.dequeue());
        }
        MyQueue temp = q1;
        q1 = q2;
        q2 = temp;
        cout << val << " pushed to the stack." << endl;
    }

    void pop() {
        if (q1.isEmpty()) {
            cout << "Stack is empty. Cannot pop." << endl;
            return;
        }
        int val = q1.dequeue();
        cout << val << " popped from the stack." << endl;
    }

    bool isEmpty() {
        return q1.isEmpty();
    }
};

int main() {
    StackUsingTwoQueues s;
    s.push(10);
    s.push(20);
    s.pop();
    s.pop();
    s.pop();
    return 0;
}
