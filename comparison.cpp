#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    string str1="Gray";
    string str2="Fraz";
    if(str1==str2){
        cout<<"SAME"<<endl;
    }else{
        cout<<"NOT SAME"<<endl;
    }
    int flag=1;
    // for(int i=0;i<4;i++){
    //     if(toupper(str1[i]!=toupper(str2[i]))){
    //         flag=0;
    //         break;
    //     }
    // }
    cout<<str1.compare(str2);
    return 0;
}