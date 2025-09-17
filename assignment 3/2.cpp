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

    bool isEmpty() {
        return top < 0;
    }
};

int main() {
    CharStack s;
    string str;
    cout << "Enter a string to reverse: ";
    getline(cin, str);

    for (char c : str) {
        s.push(c);
    }

    string reversedStr = "";
    while (!s.isEmpty()) {
        reversedStr += s.pop();
    }
    cout << "Reversed string: " << reversedStr << endl;
    return 0;
}
