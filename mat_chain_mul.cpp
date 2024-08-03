#include <bits/stdc++.h>
using namespace std;

// Link : https://www.geeksforgeeks.org/problems/matrix-chain-multiplication/1
// Time : O(N^3)

class Solution{
    int dp[105][105];
public:
    int matMulHelper(int arr[], int i, int j) { // answer of matrix[i .... j]
        if(i >= j) // Less than or equal to 1 matrix
            return 0;
        
        if(dp[i][j] != -1)
            return dp[i][j];
        
        // Let's assume that last multiplication
        // is like mat[i ... k] * mat[k+1 ... j]
        dp[i][j] = INT_MAX;
        for(int k = i; k < j; ++k) {
            int furtherCost = matMulHelper(arr, i, k) + matMulHelper(arr, k + 1, j);
            int curCost = arr[i-1]*arr[k]*arr[j];
            dp[i][j] = min(dp[i][j], curCost + furtherCost);
        }
        return dp[i][j];
    }
    
    int matrixMultiplication(int N, int arr[]) {
        memset(dp, -1, sizeof(dp));
        int n = N - 1; // number of matrices
        return matMulHelper(arr, 1, n);
    }
};

int main() {
	// your code goes here
	return 0;
}