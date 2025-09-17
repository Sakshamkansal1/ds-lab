#include <iostream>
using namespace std;

int main() {
    int n = 4;
    int tri[10] = {0}; 

    tri[0]=2; 
    tri[1]=3; tri[2]=4; tri[3]=5; 
    tri[4]=6; tri[5]=7; tri[6]=8; 
    tri[7]=9; tri[8]=10; 

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i-j==0) cout<<tri[i-1]<<" ";
            else if(i-j==1) cout<<tri[n+j-1]<<" ";
            else if(j-i==1) cout<<tri[2*n+i-2]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

