#include <iostream>

using namespace std;

const int MAX_SIZE = 100;
int qArr[MAX_SIZE];
int qFront = -1, qRear = -1;
int qSize = 0;

bool qIsEmpty() {
    return qSize == 0;
}

void qEnqueue(int val) {
    if (qSize == MAX_SIZE) return;
    if (qIsEmpty()) qFront = 0;
    qRear = (qRear + 1) % MAX_SIZE;
    qArr[qRear] = val;
    qSize++;
}

int qDequeue() {
    if (qIsEmpty()) return -1;
    int val = qArr[qFront];
    qFront = (qFront + 1) % MAX_SIZE;
    qSize--;
    if (qIsEmpty()) {
        qFront = -1;
        qRear = -1;
    }
    return val;
}

void qDisplay() {
    if (qIsEmpty()) {
        cout << "Queue is empty." << endl;
        return;
    }
    int current = qFront;
    for (int i = 0; i < qSize; i++) {
        cout << qArr[current] << " ";
        current = (current + 1) % MAX_SIZE;
    }
    cout << endl;
}

void interleave() {
    if (qSize % 2 != 0) {
        cout << "Queue size must be even." << endl;
        return;
    }
    int halfSize = qSize / 2;
    int tempArr[halfSize];

    for (int i = 0; i < halfSize; i++) {
        tempArr[i] = qDequeue();
    }

    for (int i = 0; i < halfSize; i++) {
        qEnqueue(tempArr[i]);
    }

    for (int i = 0; i < halfSize; i++) {
        qEnqueue(qDequeue());
    }

    for (int i = 0; i < halfSize; i++) {
        tempArr[i] = qDequeue();
    }

    for (int i = 0; i < halfSize; i++) {
        qEnqueue(tempArr[i]);
        qEnqueue(qDequeue());
    }
}

int main() {
    qEnqueue(4);
    qEnqueue(7);
    qEnqueue(11);
    qEnqueue(20);
    qEnqueue(5);
    qEnqueue(9);

    cout << "Original queue: ";
    qDisplay();

    interleave();

    cout << "Interleaved queue: ";
    qDisplay();

    return 0;
}
