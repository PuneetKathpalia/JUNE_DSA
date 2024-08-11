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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(root == NULL) return {};
        vector<vector<int>> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(q.size() > 0) {
            int size = q.size();
            vector<int> level_vector(size);
            for(int i = 0; i < size; i++) {
                TreeNode* candidate = q.front();
                level_vector[i] = candidate->val;
                q.pop();
                if(candidate->left != NULL) {
                    q.push(candidate->left);
                }
                if(candidate->right != NULL) {
                    q.push(candidate->right);
                }
            }
            ans.push_back(level_vector);
        }        
        return ans;
    }
};