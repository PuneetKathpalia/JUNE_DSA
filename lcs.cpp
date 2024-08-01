// class Solution {
// public:
//     int longestCommonSubsequenceHelper(int i, int j, string &text1, string &text2, int dp[1001][1001]) {
//         if(i == text1.size() || j == text2.size()) return 0;
//         if(dp[i][j] != -1) return dp[i][j];
//         if(text1[i] == text2[j]) {
//             return dp[i][j] = 1 + longestCommonSubsequenceHelper(i+1,j+1,text1,text2, dp);
//         } else {
//             int op1, op2;
//             op1 = longestCommonSubsequenceHelper(i+1, j, text1, text2, dp);
//             op2 = longestCommonSubsequenceHelper(i, j+1, text1, text2, dp);
//             return dp[i][j] = max(op1 ,op2);
//         }
//     }
//     int longestCommonSubsequence(string text1, string text2) {
//         int dp[1001][1001];
//         memset(dp, -1, sizeof dp);
//         return longestCommonSubsequenceHelper(0, 0, text1, text2, dp);
//     }
// };