#include <bits/stdc++.h>
using namespace std;

// Link : https://www.geeksforgeeks.org/problems/minimum-platforms/1
// Time : O(NlogN)

class Solution{
    public:
    //Function to find the minimum number of platforms required at the
    //railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        vector<pair<int,int> > trains(n);
        for(int i = 0; i < n; ++i) {
            trains[i] = {arr[i], dep[i]};
        }
        sort(trains.begin(), trains.end());
        
        priority_queue <int, vector<int>, greater<int> > pq;
        
        for(pair<int,int> tr : trains) {
            int curStart = tr.first, curEnd = tr.second;
            if(pq.empty()) {
                pq.push(curEnd);
            }
            else if(pq.top() < curStart) {
                pq.pop();
                pq.push(curEnd);
            }
            else {
                pq.push(curEnd);
            }
        }
        return pq.size();
    }
};


//{ Driver Code Starts.
// Driver code
int main()
{
    int t;
    cin>>t;
    while(t--) 
    {
        int n;
        cin>>n;
        int arr[n];
        int dep[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        for(int j=0;j<n;j++){
            cin>>dep[j];
        }
        Solution ob;
        cout <<ob.findPlatform(arr, dep, n)<<endl;
    } 
   return 0;
}