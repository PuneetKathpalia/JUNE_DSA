#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    int fibo(int n){
       if(n==0||n==1)
       return n;
       int a=fibo(n-1);
       int b=fibo(n-2);
       return a+b; 
    }
int main(){
    cout<<fibo(10);
    return 0;
}