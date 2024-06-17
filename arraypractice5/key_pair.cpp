// //{ Driver Code Starts
// #include <bits/stdc++.h>

// using namespace std;


// // } Driver Code Ends
// //User function template for C++
// class Solution{
// public:	
// 	// Function to check if array has 2 elements
// 	// whose sum is equal to the given value
// 	bool hasArrayTwoCandidates(int arr[], int n, int x) {
// 	    int my_memory[100001]={0};
// 	    for (int i=0;i<n;i++){
// 	        int curr_num=arr[i];
// 	        int req_num=x-curr_num;
// 	           if(req_num<=10000 && req_num>0 && my_memory[req_num]==1){
// 	               return true;
// 	           }
// 	           my_memory[curr_num]=1;
// 	    }
// 	    return false;
// 	}
// };

// //{ Driver Code Starts.

// int main() {
//     int t;
//     cin >> t;
//     while (t--) {
//         int n, x;
//         cin >> n >> x;
//         int arr[n];
//         for (int i = 0; i < n; i++) {
//             cin >> arr[i];
//         }
//         Solution ob;
//         auto ans = ob.hasArrayTwoCandidates(arr, n, x);
//         cout << (ans ? "Yes\n" : "No\n");
//     }
//     return 0;
// }

// // } Driver Code Ends