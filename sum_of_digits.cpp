#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int count;
    cin>>count;

    for(int i=1;i<=count;i++){
        int number;
        cin>>number;
        int sum=0;

    for (int i=number;i>0;i/=10){
        sum+=(i%10);
    }
    cout<<sum<<endl;
    }
    return 0;
}