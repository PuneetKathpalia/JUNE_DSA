#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    string str;
    cin>>str;
    // string reverse_str=str;
    // int n=str.size();
    // for(int i=0;i<n/2;i++){
    //     swap(reverse_str[i],reverse_str[n-i-1]);
    // }
    // if(reverse_str==str){
    //     cout<<"yes"<<endl;
    // }else{
    //     cout<<"no"<<endl;
    // }

    int n=str.size();
    int flag=1;
    for(int i=0;i<n/2;i++){
        if(str[i]!=str[n-i-1]){
            flag=0;
            break;
        }
    }
    if (flag==1){
        cout<<"yes"<<endl;
    }else{
        cout<<"no"<<endl;
    }
    return 0;
}