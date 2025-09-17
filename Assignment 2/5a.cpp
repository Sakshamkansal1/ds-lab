#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int d[4] = {0};

    d[0] = 5; d[1] = 8; d[2] = 9; d[3] = 12;

    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) cout<<d[i]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

