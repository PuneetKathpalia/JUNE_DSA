class Solution {
public:
    int uniquePathsWithObstaclesHelper(int i, int j, int m,int n, int dp[101][101],vector<vector<int>>& obstacleGrid) {
        if(i >= m || j >= n) return 0;
        if(obstacleGrid[i][j] == 1) return 0;
        if(i == m-1 && j == n-1) return 1;
        if(dp[i][j] != -1) return dp[i][j];
        int pathsFromRight =  uniquePathsWithObstaclesHelper(i, j+1, m, n, dp, obstacleGrid);
        int pathsFromDown = uniquePathsWithObstaclesHelper(i+1, j, m, n, dp, obstacleGrid);
        return dp[i][j] = pathsFromRight + pathsFromDown;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        int m = obstacleGrid.size();
        int n = obstacleGrid[0].size();
        return uniquePathsWithObstaclesHelper(0 ,0, m, n, dp, obstacleGrid);
    }
};