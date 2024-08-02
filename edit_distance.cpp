// Link : https://leetcode.com/problems/longest-increasing-subsequence/
// Time : O(N^2)
class Solution {
public:
    int minDistanceHelper(string &word1, string &word2, int i, int j, int dp[501][501]) {
        if(i == word1.size() && j == word2.size()) return 0;
        if(i == word1.size()) {
            return word2.size() - j;
        }
        if(j == word2.size()) {
            return word1.size() - i;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i] == word2[j]) {
            // if the chars at i and j are same
            return dp[i][j] = minDistanceHelper(word1, word2, i+1, j+1, dp);
        } else {
            // if the chars are not same at i and j

            // insert the char at j in word1
            int op1 = 1 + minDistanceHelper(word1, word2, i, j+1, dp);

            // delete the ith char in word1
            int op2 = 1 + minDistanceHelper(word1, word2, i+1, j, dp);

            // replace the char at i with the char at j
            int op3 = 1 + minDistanceHelper(word1, word2, i+1, j+1, dp);

            return dp[i][j] = min({op1,op2,op3});

        }
        
    }
    int minDistance(string word1, string word2) {
        int dp[501][501];
        memset(dp, -1, sizeof dp);
        return minDistanceHelper(word1, word2, 0, 0, dp);
    }
};