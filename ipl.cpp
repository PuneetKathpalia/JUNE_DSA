#include <bits/stdc++.h>
using namespace std;

// Link : https://www.geeksforgeeks.org/problems/ipl-2021-match-day-2--141634/1

class Solution {
  public:
    vector<int> max_of_subarrays(vector<int> arr, int n, int k) {
        deque<int> q;
        vector<int> ans;
        for(int i = 0; i < n; ++i) {
            
            // push the current element strategically
            while(!q.empty() && arr[q.back()] <= arr[i])
                q.pop_back();
            q.push_back(i);
            
            // if the front() element doesn't belong
            // to the current window, pop it.
            if(q.front() <= i - k)
                q.pop_front();
                
            if(i >= k - 1) // because if i < k - 1, then window is not of size k
                ans.push_back(arr[q.front()]);
        }
        return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}