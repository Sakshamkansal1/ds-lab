#include <iostream>
#include <string>
using namespace std;
int main(){
    string s="datastructures",res="";
    for(char c:s){
        if(string("aeiouAEIOU").find(c)==string::npos){
            res+=c;
        }
    }
    cout<<res;
}

