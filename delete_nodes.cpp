/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_set<int> toDeleteSet(to_delete.begin(), to_delete.end());
        vector<TreeNode*> forest;
        
        // Recursive function to process each node
        function<TreeNode*(TreeNode*, bool)> dfs = [&](TreeNode* node, bool isRoot) -> TreeNode* {
            if (!node) return nullptr;

            bool toDelete = toDeleteSet.count(node->val);
            if (isRoot && !toDelete) {
                forest.push_back(node);
            }

            node->left = dfs(node->left, toDelete);
            node->right = dfs(node->right, toDelete);

            return toDelete ? nullptr : node;
        };
        
        dfs(root, true);
        return forest;
    }
};