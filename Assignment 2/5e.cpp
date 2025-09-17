#include <iostream>
using namespace std;

int main() {
    int n=4;
    int sym[10]={0};

    sym[0]=1; 
    sym[1]=2; sym[2]=3; 
    sym[3]=4; sym[4]=5; sym[5]=6; 
    sym[6]=7; sym[7]=8; sym[8]=9; sym[9]=10;

    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j) cout<<sym[(i*(i-1))/2+(j-1)]<<" ";
            else cout<<sym[(j*(j-1))/2+(i-1)]<<" ";
        }
        cout<<endl;
    }
}

