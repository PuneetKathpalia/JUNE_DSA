#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
    int fact(int n){
        if(n==0){
            return 1;
        }
        int part=fact(n-1);
        int ans=part*n;
        return ans; 
   };
int main(){
    int n;
    cin>>n;
    cout<<fact(n);
    return 0;
}