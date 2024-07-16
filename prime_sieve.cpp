// /**
//  * Definition for a binary tree node.
//  * struct TreeNode {
//  *     int val;
//  *     TreeNode *left;
//  *     TreeNode *right;
//  *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
//  *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
//  * };
//  */
// class Solution {
// public:
//     // Helper function to find the path from root to a given target node.
//     bool findPath(TreeNode* root, int target, string &path) {
//         if (!root) return false;
//         if (root->val == target) return true;
        
//         path.push_back('L');
//         if (findPath(root->left, target, path)) return true;
//         path.pop_back();
        
//         path.push_back('R');
//         if (findPath(root->right, target, path)) return true;
//         path.pop_back();
        
//         return false;
//     }
    
//     string getDirections(TreeNode* root, int startValue, int destValue) {
//         string pathToStart, pathToDest;
        
//         // Find paths from root to startValue and destValue.
//         findPath(root, startValue, pathToStart);
//         findPath(root, destValue, pathToDest);
        
//         // Find the first index where the paths differ.
//         int i = 0;
//         while (i < pathToStart.size() && i < pathToDest.size() && pathToStart[i] == pathToDest[i]) {
//             i++;
//         }
        
//         // Construct the result path:
//         // 'U' for each step back to the common ancestor from startValue
//         // then the remaining path from the common ancestor to destValue.
//         string result(pathToStart.size() - i, 'U');
//         result += pathToDest.substr(i);
        
//         return result;
//     }
// };
