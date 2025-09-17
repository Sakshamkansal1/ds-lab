#include <iostream>

using namespace std;

const int MAX_SIZE = 100;

class StackArray {
private:
    int arr[MAX_SIZE];
    int top;

public:
    StackArray() {
        top = -1;
    }

    void push(int val) {
        if (isFull()) {
            cout << "Stack Overflow! Cannot push " << val << endl;
            return;
        }
        arr[++top] = val;
        cout << val << " pushed to stack." << endl;
    }

    int pop() {
        if (isEmpty()) {
            cout << "Stack Underflow! Cannot pop." << endl;
            return -1;
        }
        int poppedVal = arr[top--];
        cout << "Popped value: " << poppedVal << endl;
        return poppedVal;
    }

    int peek() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return -1;
        }
        return arr[top];
    }

    bool isEmpty() {
        return top == -1;
    }

    bool isFull() {
        return top == MAX_SIZE - 1;
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty." << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i <= top; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    StackArray s;
    int choice, val;
    do {
        cout << "\n--- Stack Operations Menu ---" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Peek" << endl;
        cout << "4. Check if Empty" << endl;
        cout << "5. Check if Full" << endl;
        cout << "6. Display" << endl;
        cout << "7. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                s.push(val);
                break;
            case 2:
                s.pop();
                break;
            case 3:
                val = s.peek();
                if (val != -1) {
                    cout << "Top element is: " << val << endl;
                }
                break;
            case 4:
                if (s.isEmpty()) {
                    cout << "Stack is empty." << endl;
                } else {
                    cout << "Stack is not empty." << endl;
                }
                break;
            case 5:
                if (s.isFull()) {
                    cout << "Stack is full." << endl;
                } else {
                    cout << "Stack is not full." << endl;
                }
                break;
            case 6:
                s.display();
                break;
            case 7:
                cout << "Exiting Stack Menu." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 7);
    return 0;
}
