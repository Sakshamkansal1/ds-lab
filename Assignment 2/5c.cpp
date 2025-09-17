#include <iostream>
using namespace std;

int main() {
    int n=4;
    int lower[10]={0}; 

    lower[0]=1; 
    lower[1]=2; lower[2]=3;
    lower[3]=4; lower[4]=5; lower[5]=6;
    lower[6]=7; lower[7]=8; lower[8]=9; lower[9]=10;

    int k=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i>=j) cout<<lower[(i*(i-1))/2+(j-1)]<<" ";
            else cout<<"0 ";
        }
        cout<<endl;
    }
}

