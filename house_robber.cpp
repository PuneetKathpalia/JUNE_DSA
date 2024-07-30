class Solution {
public:
    int robHelper(vector<int>& nums, int i, vector<int> &dp) {
        if(i >= nums.size()) return 0;
        if(dp[i] != -1) return dp[i];
        int op1 = 0, op2 = 0;
        // to take it
        op1 += nums[i];
        op1 += robHelper(nums, i+2, dp);
        // leave it
        op2 += robHelper(nums, i+1, dp);
        return dp[i] = max(op1, op2);
    }
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size()+9, -1);
        return robHelper(nums,0,dp);
    }
};