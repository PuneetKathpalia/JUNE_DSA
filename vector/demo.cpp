// #include <bits/stdc++.h>

// using namespace std;

// int main() {
//     vector<int> v;
//     for(int i = 0; i < 20; ++i) {
//         cout << v.size() << ' ' << v.capacity() << '\n';
//         v.push_back(i);
//     }
//   return 0;
// }

#include<iostream>
#include<bits/stdc++.h>
using namespace std;
  
int main(){
 vector<int>v2;
 vector<int>v1;
 vector<int>v2(5,10);

 vector<int> v3={5,1,3,2};
 cout<<v2.size()<<" ";

 for(int val: v2){
  cout<<val<<" ";
  cout<<'\n';
 } 

 for(int val: v3){
  cout<<val<<" ";
  cout<<'\n';

  v1.push_back(5);
  v3.push_back(5);
  v3.push_back(5);

 for(int val: v3){
  cout<<val<<" ";
  cout<<'\n';
} 
 for(int i=0;i<v3.size();i++){
  cout<<v1[i]<<" ";
  cout<<'\n';
 }
 }
  return 0;
}

// POSSIBLE SOLUTIONS 1 
//1. Just use a really large array 
//POSSIBLE SOLUTION 2
//1. create an array of size 100
//2. new array created and the element from old array will be copied to the new array 
