#include <iostream>
using namespace std;
int main(){
    int arr[]={1,2,3,5,6};
    int n=6;
    int sum=n*(n+1)/2,s=0;
    for(int i=0;i<n-1;i++){
        s+=arr[i];
    }
    cout<<"Missing: "<<sum-s;
}

