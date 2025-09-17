#include <iostream>
using namespace std;

#define MAX 100

int arr[MAX], n = 0;

// CREATE
void create() {
    cout << "\nEnter the number of elements (max " << MAX << "): ";
    cin >> n;

    if (n > MAX || n <= 0) {
        cout << "Invalid size. Please try again.\n";
        n = 0;
        return;
    }

    cout << "Enter " << n << " elements: ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << "Array created successfully.\n";
}

// DISPLAY
void display() {
    if (n == 0) {
        cout << "\nArray is empty. Create it first.\n";
        return;
    }
    cout << "\nCurrent Array: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\n";
}

// INSERT
void insertElement() {
    if (n == MAX) {
        cout << "\nArray is full. Cannot insert more elements.\n";
        return;
    }

    int pos, val;
    cout << "\nEnter position to insert (1 to " << n + 1 << "): ";
    cin >> pos;
    if (pos < 1 || pos > n + 1) {
        cout << "Invalid position. Please try again.\n";
        return;
    }

    cout << "Enter the value to insert: ";
    cin >> val;

    for (int i = n; i >= pos; i--)
        arr[i] = arr[i - 1];

    arr[pos - 1] = val;
    n++;

    cout << "Element inserted successfully.\n";
}

// DELETE
void deleteElement() {
    if (n == 0) {
        cout << "\nArray is empty. Nothing to delete.\n";
        return;
    }

    int pos;
    cout << "\nEnter position to delete (1 to " << n << "): ";
    cin >> pos;
    if (pos < 1 || pos > n) {
        cout << "Invalid position. Please try again.\n";
        return;
    }

    for (int i = pos - 1; i < n - 1; i++)
        arr[i] = arr[i + 1];

    n--;
    cout << "Element deleted successfully.\n";
}

// LINEAR SEARCH
void linearSearch() {
    if (n == 0) {
        cout << "\nArray is empty. Create it first.\n";
        return;
    }

    int key, found = -1;
    cout << "\nEnter the element to search: ";
    cin >> key;

    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            found = i;
            break;
        }
    }

    if (found != -1)
        cout << "Element found at position: " << found + 1 << "\n";
    else
        cout << "Element not found in the array.\n";
}

int main() {
    int choice;
    do {
        cout << "\n========= ARRAY OPERATIONS MENU =========";
        cout << "\n1. Create Array";
        cout << "\n2. Display Array";
        cout << "\n3. Insert Element";
        cout << "\n4. Delete Element";
        cout << "\n5. Search Element (Linear Search)";
        cout << "\n6. Exit";
        cout << "\n-----------------------------------------";
        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: create(); break;
            case 2: display(); break;
            case 3: insertElement(); break;
            case 4: deleteElement(); break;
            case 5: linearSearch(); break;
            case 6: cout << "\nExiting program.\n"; break;
            default: cout << "\nInvalid choice. Please try again.\n";
        }
    } while (choice != 6);

    return 0;
}
