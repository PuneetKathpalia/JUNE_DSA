#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/subarray-sum-equals-k/

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> preSumCnt;
        
        // Update preSum[-1] i.e. 0
        preSumCnt[0] = 1;

        int preSum = 0, ans = 0;
        for(int en = 0; en < nums.size(); ++en) {
            preSum += nums[en]; // preSum = prefix_sum[en]

            // We want count of x s.t.
            // pre[en] - pre[x] = k
            // therefore, pre[x] = pre[en] - k
            ans += preSumCnt[preSum - k];

            // Now, update the count for pre[j]
            // as well.
            preSumCnt[preSum] += 1;
        }

        return ans;
    }
};

int main() {
	// your code goes here
	return 0;
}
