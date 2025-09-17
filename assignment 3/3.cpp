#include <iostream>
#include <string>

using namespace std;

const int MAX_SIZE = 100;

class CharStack {
private:
    char arr[MAX_SIZE];
    int top;

public:
    CharStack() {
        top = -1;
    }

    void push(char c) {
        if (top >= MAX_SIZE - 1) {
            return;
        }
        arr[++top] = c;
    }

    char pop() {
        if (top < 0) {
            return '\0';
        }
        return arr[top--];
    }

    char peek() {
        if (top < 0) {
            return '\0';
        }
        return arr[top];
    }

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    CharStack s;
    string expr;
    cout << "Enter an expression to check for balanced parentheses: ";
    getline(cin, expr);

    bool balanced = true;
    for (char c : expr) {
        if (c == '(' || c == '{' || c == '[') {
            s.push(c);
        } else if (c == ')' || c == '}' || c == ']') {
            if (s.isEmpty()) {
                balanced = false;
                break;
            }
            char topChar = s.peek();
            s.pop();
            if ((c == ')' && topChar != '(') ||
                (c == '}' && topChar != '{') ||
                (c == ']' && topChar != '[')) {
                balanced = false;
                break;
            }
        }
    }

    if (!s.isEmpty()) {
        balanced = false;
    }

    if (balanced) {
        cout << "The expression has balanced parentheses." << endl;
    } else {
        cout << "The expression does not have balanced parentheses." << endl;
    }
    return 0;
}
