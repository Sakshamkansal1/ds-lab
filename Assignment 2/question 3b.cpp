#include <iostream>
using namespace std;
int findMissing(int arr[],int n){
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m]==m+1){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return l+1;
}
int main(){
    int arr[]={1,2,3,4,6,7};
    int n=6;
    cout<<"Missing: "<<findMissing(arr,n);
}

