class Solution{
    static int matrixMultiplication(int N, int arr[])
    {
        int n = N - 1;
        int dp[][] = new int[105][105];
        for(int len = 1; len <= n; ++len) {
            for(int i = 1, j = len; i <= n && j <= n; ++i, ++j) {
                if(i == j) {
                    dp[i][j] = 0;
                    continue;
                }
                dp[i][j] = Integer.MAX_VALUE;
                for(int k = i; k < j; ++k) {
                    int curCost = arr[i-1]*arr[k]*arr[j];
                    int recurCost = dp[i][k] + dp[k+1][j];
                    dp[i][j] = Math.min(dp[i][j], curCost + recurCost);
                }
            }
        }
        return dp[1][n];
    }
}