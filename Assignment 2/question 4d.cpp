#include <iostream>
#include <string>
using namespace std;
int main(){
    string arr[5]={"pear","apple","mango","banana","grape"};
    int n=5;
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(arr[i]>arr[j]){
                string t=arr[i];
                arr[i]=arr[j];
                arr[j]=t;
            }
        }
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<endl;
    }
}

