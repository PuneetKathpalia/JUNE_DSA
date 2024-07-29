// class Solution {
// public:
//     vector<vector<string>> ans;
//     bool isSafe(int i, int j, vector<string>& chessBoard, int n) {
//         int temp_i = i, temp_j = j;
//         // top left
//         while(temp_i >=0 && temp_j >=0) {
//             if(chessBoard[temp_i][temp_j] == 'Q') return false;
//             temp_i--;
//             temp_j--;
//         }
//         temp_i = i;
//         temp_j = j;
//         // top
//         while(temp_i >=0) {
//             if(chessBoard[temp_i][temp_j] == 'Q') return false;
//             temp_i--;
//         }

//         temp_i = i;
//         temp_j = j;
//         // top right
//         while(temp_i >=0 && temp_j < n) {
//             if(chessBoard[temp_i][temp_j] == 'Q') return false;
//             temp_i--;
//             temp_j++;
//         }
//         return true;
//     }
//     void solveNQueensHelper(int i, int n,vector<string>& chessBoard) {
//         if(i == n) {
//             ans.push_back(chessBoard);
//             return;
//         }
//         for(int j = 0; j < n; j++) {
//             if(isSafe(i, j, chessBoard, n)) {
//                 chessBoard[i][j] = 'Q';
//                 solveNQueensHelper(i+1, n, chessBoard);
//                 chessBoard[i][j] = '.';
//             }
//         }
        
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         string row(n,'.');
//         vector<string> chess_board(n,row);
//         solveNQueensHelper(0,n,chess_board);
//         return ans;
//     }
// };