#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int l,r;
    cin>>l>>r;
    for (int i=l;i<=r;i++){
        int sum=0;
        for (int j=i;j>0;j/=10){
        sum+=(j%10);
    }
    cout<<sum<<endl;
    }
    
    return 0;
}