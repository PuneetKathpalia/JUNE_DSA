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
    vector<long long> isValidBSTHelper(TreeNode* root) {
        if(root == NULL) return {1,LLONG_MAX,LLONG_MIN};
        vector<long long> l = isValidBSTHelper(root->left);
        vector<long long> r = isValidBSTHelper(root->right);
        long long max_left = l[2];
        long long min_right = r[1];
        bool isBST = false;
        if((long long)root->val > max_left && (long long)root->val < min_right) {
            isBST = true;
        }
        isBST = isBST & l[0] & r[0];
        return {isBST, min({(long long)root->val, min_right, l[1]}), max({(long long)root->val, r[2], max_left})};
    }
    bool isValidBST(TreeNode* root) {
        vector<long long> ans = isValidBSTHelper(root);
        return ans[0];
    }
};