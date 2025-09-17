#include <iostream>
#include <string>

using namespace std;

const int ALPHABET_SIZE = 26;
const int MAX_Q_SIZE = 100;

char qArr[MAX_Q_SIZE];
int qFront = -1, qRear = -1;
int qSize = 0;

bool qIsEmpty() {
    return qSize == 0;
}

void qEnqueue(char val) {
    if (qSize == MAX_Q_SIZE) return;
    if (qIsEmpty()) qFront = 0;
    qRear = (qRear + 1) % MAX_Q_SIZE;
    qArr[qRear] = val;
    qSize++;
}

char qDequeue() {
    if (qIsEmpty()) return '\0';
    char val = qArr[qFront];
    qFront = (qFront + 1) % MAX_Q_SIZE;
    qSize--;
    if (qIsEmpty()) {
        qFront = -1;
        qRear = -1;
    }
    return val;
}

char qPeek() {
    if (qIsEmpty()) return '\0';
    return qArr[qFront];
}

int main() {
    string sample = "aabcc";
    int freq[ALPHABET_SIZE] = {0};

    cout << "Sample Input: " << sample << endl;
    cout << "Output: ";

    for (char c : sample) {
        freq[c - 'a']++;
        qEnqueue(c);

        while (!qIsEmpty()) {
            if (freq[qPeek() - 'a'] > 1) {
                qDequeue();
            } else {
                cout << qPeek() << " ";
                break;
            }
        }

        if (qIsEmpty()) {
            cout << "-1 ";
        }
    }
    cout << endl;
    return 0;
}
