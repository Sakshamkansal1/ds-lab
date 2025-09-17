#include <iostream>
using namespace std;

struct Term {
    int row, col, val;
};

int main() {
    int n;
    cout<<"Enter number of nonzero elements: ";
    cin>>n;

    Term a[20], t[20];
    cout<<"Enter row col value:\n";
    for(int i=0;i<n;i++)
        cin>>a[i].row>>a[i].col>>a[i].val;

    for(int i=0;i<n;i++) {
        t[i].row=a[i].col;
        t[i].col=a[i].row;
        t[i].val=a[i].val;
    }

    cout<<"\nTranspose (row col val):\n";
    for(int i=0;i<n;i++)
        cout<<t[i].row<<" "<<t[i].col<<" "<<t[i].val<<"\n";
}

