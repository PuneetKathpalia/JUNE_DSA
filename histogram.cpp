// class Solution {
// public:
//     int maximumGain(string s, int x, int y) {
//         if (x < y) {
//             swap(x, y);
//             for (char &c : s) {
//                 if (c == 'a') c = 'b';
//                 else if (c == 'b') c = 'a';
//             }
//         }

//         int points = 0;
//         stack<char> stk;
//         for (char c : s) {
//             if (!stk.empty() && stk.top() == 'a' && c == 'b') {
//                 stk.pop();
//                 points += x;
//             } else {
//                 stk.push(c);
//             }
//         }

//         string remaining;
//         while (!stk.empty()) {
//             remaining += stk.top();
//             stk.pop();
//         }
//         reverse(remaining.begin(), remaining.end());

//         for (char c : remaining) {
//             if (!stk.empty() && stk.top() == 'b' && c == 'a') {
//                 stk.pop();
//                 points += y;
//             } else {
//                 stk.push(c);
//             }
//         }

//         return points;
//     }
// };
