// class Solution {
// public:
//     vector<vector<string>> ans;
//     bool isSafe(int i, int j, vector<string>& chessBoard, int n, vector<int>& col, vector<int> &diagonal_1, vector<int>& diagonal_2) {
//         // top left
//         if(diagonal_1[i-j+n-1] == 1) return false;
//         // top
//         if(col[j] == 1) return false;
//         // top right
//         if(diagonal_2[i+j] == 1) return false;
//         return true;
//     }
//     void solveNQueensHelper(int i, int n,vector<string>& chessBoard, vector<int>& col, vector<int>& diagonal_1, vector<int>& diagonal_2) {
//         if(i == n) {
//             ans.push_back(chessBoard);
//             return;
//         }
//         for(int j = 0; j < n; j++) {
//             if(isSafe(i, j, chessBoard, n, col, diagonal_1, diagonal_2)) {
//                 chessBoard[i][j] = 'Q';
//                 col[j] = 1;
//                 diagonal_1[i-j+n-1] = 1;
//                 diagonal_2[i+j] = 1;
//                 solveNQueensHelper(i+1, n, chessBoard, col, diagonal_1, diagonal_2);
//                 col[j] = 0;
//                 diagonal_1[i-j+n-1] = 0;
//                 diagonal_2[i+j] = 0;
//                 chessBoard[i][j] = '.';
//             }
//         }
        
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         string row(n,'.');
//         vector<string> chess_board(n,row);
//         vector<int> col(n,0);
//         vector<int> diagonal_1(2*n-1,0);
//         vector<int> diagonal_2(2*n-1,0);
//         solveNQueensHelper(0,n,chess_board,col,diagonal_1, diagonal_2);
//         return ans;
//     }
// };