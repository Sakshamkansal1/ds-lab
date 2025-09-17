#include <iostream>
using namespace std;

int main() {
    int r,c;
    cout << "Enter rows and columns: ";
    cin >> r >> c;

    int a[10][10];
    cout << "Enter elements:\n";
    for (int i=0;i<r;i++) {
        for (int j=0;j<c;j++) {
            cin >> a[i][j];
        }
    }

    cout << "Sum of each row:\n";
    for (int i=0;i<r;i++) {
        int sum=0;
        for (int j=0;j<c;j++) {
            sum += a[i][j];
        }
        cout << "Row " << i+1 << ": " << sum << endl;
    }

    cout << "Sum of each column:\n";
    for (int j=0;j<c;j++) {
        int sum=0;
        for (int i=0;i<r;i++) {
            sum += a[i][j];
        }
        cout << "Column " << j+1 << ": " << sum << endl;
    }

    return 0;
}
