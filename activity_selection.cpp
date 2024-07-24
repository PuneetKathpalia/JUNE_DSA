#include<bits/stdc++.h>
using namespace std;

// Link : https://www.geeksforgeeks.org/problems/activity-selection/1
// Time : O(NlogN)

bool cmp(pair<int,int> p1, pair<int,int> p2) {
    return p1.second < p2.second;
}

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        vector<pair<int,int> > act(n);
        
        for(int i = 0; i < n; ++i) {
            act[i] = {start[i], end[i]};
        }
        
        sort(act.begin(), act.end(), cmp);
        
        int maxActivities = 1, lastEnd = act[0].second;
        for(int i = 1; i < n; ++i) {
            int curStart = act[i].first;
            if(curStart > lastEnd) {
                maxActivities += 1;
                lastEnd = act[i].second;
            }
        }
        
        return maxActivities;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    
    //testcases
    cin >> t;
    while(t--)
    {
        //size of array
        int n;
        cin >> n;
        vector<int> start(n), end(n);
        
        //adding elements to arrays start and end
        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        //function call
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}