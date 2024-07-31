#include <bits/stdc++.h>
using namespace std;

// Link : https://leetcode.com/problems/unique-paths/
// Time & Space : O(M*N)

// int uniquePathsHelper(int i, int j, int m,int n, int dp[101][101]) {
// 	if(i == m-1 && j == n-1) return 1;
// 	if(i >= m || j >= n) return 0;
// 	if(dp[i][j] != -1) return dp[i][j];
// 	int pathsFromRight =  uniquePathsHelper(i, j+1, m, n, dp);
// 	int pathsFromDown = uniquePathsHelper(i+1, j, m, n, dp);
// 	return dp[i][j] = pathsFromRight + pathsFromDown;
// }
int uniquePaths(int m, int n) {
	int dp[m+1][n+1];
	memset(dp, 0, sizeof(dp));
	dp[m-1][n-1] = 1;
	for(int i = m-1;i >= 0; i--) {
		for(int j = n-1; j >= 0; j--) {
			if(i == m-1 && j == n-1) continue;
			dp[i][j] = dp[i+1][j] + dp[i][j+1];
		}
	}
	return dp[0][0];
}