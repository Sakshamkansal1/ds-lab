#include <iostream>
using namespace std;

int main() {
    int n=4;
    int upper[10]={0}; 

    upper[0]=1; upper[1]=2; upper[2]=3; upper[3]=4;
    upper[4]=5; upper[5]=6; upper[6]=7;
    upper[7]=8; upper[8]=9;
    upper[9]=10;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i<=j) cout<<upper[(j*(j-1))/2+(i-1)]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

