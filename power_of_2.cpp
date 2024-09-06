#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int n;
    cin>>n;
    if(n<=0){
        cout<<"Not Power";
    }
    while(n>1){
        if(n%2!=0){
            cout<<"Not Power"<<endl;
            break;
        }
        n=n/2;
    }
    if(n==1){
        cout<<"Power"<<endl;
    }
    return 0;
}