class Solution {
public:
    int climbStairsHelper(int i,int n, vector<int>& dp) {
        if(i > n) return dp[i] = 0;
        if(i == n) return dp[i] = 1;
        if(dp[i] != -1) {
            return dp[i];
        }
        int x = climbStairsHelper(i+1, n, dp);
        int y = climbStairsHelper(i+2, n, dp);

        return dp[i] = x+y;
    }
    int climbStairs(int n) {
       vector<int> dp(n+2, -1);
       return climbStairsHelper(0,n, dp);
    }
};