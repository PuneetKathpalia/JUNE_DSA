// #include <string>
// #include <unordered_map>
// #include <stack>
// #include <map>

// using namespace std;

// class Solution {
// public:
//     string countOfAtoms(string formula) {
//         stack<unordered_map<string, int>> st;
//         unordered_map<string, int> curr;
//         int i = 0, n = formula.size();
        
//         while (i < n) {
//             if (formula[i] == '(') {
//                 // Push current map to stack and start a new one
//                 st.push(curr);
//                 curr.clear();
//                 i++;
//             } else if (formula[i] == ')') {
//                 // End of current group, get the multiplier
//                 i++;
//                 int start = i;
//                 while (i < n && isdigit(formula[i])) i++;
//                 int multiplier = i > start ? stoi(formula.substr(start, i - start)) : 1;
                
//                 // Apply multiplier to the current map
//                 for (auto &[atom, count] : curr) {
//                     curr[atom] *= multiplier;
//                 }
                
//                 // Add current map to the top of the stack
//                 if (!st.empty()) {
//                     auto &top = st.top();
//                     for (auto &[atom, count] : curr) {
//                         top[atom] += count;
//                     }
//                     curr = move(top);
//                     st.pop();
//                 }
//             } else {
//                 // Parse atom
//                 int start = i;
//                 i++;
//                 while (i < n && islower(formula[i])) i++;
//                 string atom = formula.substr(start, i - start);
                
//                 // Parse count
//                 start = i;
//                 while (i < n && isdigit(formula[i])) i++;
//                 int count = i > start ? stoi(formula.substr(start, i - start)) : 1;
                
//                 curr[atom] += count;
//             }
//         }
        
//         // Sort and format the result
//         map<string, int> sorted(curr.begin(), curr.end());
//         string result;
//         for (auto &[atom, count] : sorted) {
//             result += atom;
//             if (count > 1) result += to_string(count);
//         }
        
//         return result;
//     }
// };
