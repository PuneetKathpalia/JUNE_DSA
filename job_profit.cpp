#include<bits/stdc++.h>
using namespace std; 

// Link : https://www.geeksforgeeks.org/problems/job-sequencing-problem/1
// Time : O(NlogN)

struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
};

bool cmp(Job j1, Job j2) {
    return j1.profit > j2.profit;
}

class Solution 
{
    public:
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n)  {
        sort(arr, arr + n, cmp);
        
        set<int> freeSlots;
        for(int i = 1; i <= n; ++i)
            freeSlots.insert(i);
        
        int jobsDone = 0, profitEarned = 0;
        for(int i = 0; i < n; ++i) {
            // Find the latest free slot
            // that is less than or equal to deadline
            auto it = freeSlots.upper_bound(arr[i].dead);
            if(it == freeSlots.begin())
                continue; // no slot.
            
            it--;
            freeSlots.erase(it); // Remove the slot
            jobsDone += 1; // increment jobs done by 1.
            profitEarned += arr[i].profit; // update the profit
        }
        return vector<int>{jobsDone, profitEarned};
    } 
};

//{ Driver Code Starts.
// Driver program to test methods 
int main() 
{ 
    int t;
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        Solution ob;
        //function call
        vector<int> ans = ob.JobScheduling(arr, n);
        cout<<ans[0]<<" "<<ans[1]<<endl;
    }
	return 0; 
}