#include<iostream>
#include<bits/stdc++.h>
using namespace std;
    
int main(){
    int n;
    cin>>n;

    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    vector <int> zeros;
    vector <int> ones;
    vector <int> twos;

    for(int i=0;i<n;i++){
        if(arr[i]==0){
            zeros.push_back(arr[i]);
        }
        else if(arr[i]==1){
            ones.push_back(arr[i]);
        }
        else{
            twos.push_back(arr[i]);
        }
    }
    
    vector<int> answer;
    answer.insert(answer.begin(),zeros.begin(),zeros.end());
    answer.insert(answer.end(),ones.begin(),ones.end());
    answer.insert(answer.end(),twos.begin(),twos.end());

    for (int i=0;i<answer.size();i++) {
        cout<<answer[i]<<" ";
    }
    return 0;
}