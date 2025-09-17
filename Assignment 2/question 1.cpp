#include <iostream>
using namespace std;
int binarySearch(int arr[],int n,int key)
{
    int l=0,h=n-1;
    while(l<=h){
        int m=(l+h)/2;
        if(arr[m]==key){
            return m;
        }
        else if(arr[m]<key){
            l=m+1;
        }
        else{
            h=m-1;
        }
    }
    return -1;
}
int main(){
    int arr[]={10,20,30,40,50,60,70};
    int n=7;
    int key=40;
    int res=binarySearch(arr,n,key);
    if(res==-1){
        cout<<"Not Found";
    }
    else{
        cout<<"Found at index "<<res;
    }
}

