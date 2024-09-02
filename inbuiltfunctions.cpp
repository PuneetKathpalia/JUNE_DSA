#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    string str="Mohammad Fraz";
    cout<<str.size()<<endl;
    cout<<str.substr(1)<<endl;
    cout<<str.substr(3)<<endl;
    cout<<str<<endl;
    cout<<str.substr(1,5)<<endl;

    str.erase(8,1);
    cout<<str<<endl;
    str.erase(0,8);
    cout<<str<<endl;

    str.insert(4,"Mohammad");
    cout<<str<<endl;
    str.insert(4," ");
    cout<<str<<endl;

    str.append("Fraz");
    cout<<str<<endl;
    return 0;
}