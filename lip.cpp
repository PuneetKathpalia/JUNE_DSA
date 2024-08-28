// https://leetcode.com/problems/longest-increasing-path-in-a-matrix/

class Solution {
    int n, m;
    vector<vector<int> > dp; // dp[i][j] -> longest path starting at (i, j)
    
    int getLen(int i, int j, vector<vector<int> > &arr) {
        if(dp[i][j] != -1)
            return dp[i][j];
        
        dp[i][j] = 1;

        // Go to larger neighbours of cell (i,j)
        int di[] = {0, 0, -1, 1};
        int dj[] = {1, -1, 0, 0};
        
        for(int k = 0; k < 4; ++k) {
            int r = i + di[k], c = j + dj[k];
            if(min(r, c) < 0 || r >= n || c >= m || arr[r][c] <= arr[i][j])
                continue;
            // (r, c) is a valid neighbour
            dp[i][j] = max(dp[i][j], 1 + getLen(r, c, arr));
        }
        return dp[i][j];
    }

public:
    int longestIncreasingPath(vector<vector<int>>& arr) {
        n = arr.size(); // no. of rows
        m = arr[0].size(); // no. of columns

        dp.assign(n, vector<int>(m, -1));

        int ans = 0;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                ans = max(ans, getLen(i, j, arr));
        
        return ans;
    }
};