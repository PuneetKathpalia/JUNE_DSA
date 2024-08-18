class Solution {
    int maxPathSumHelper(TreeNode* root, int& res){
        if(!root) return 0;
        int lMax = maxPathSumHelper(root->left, res);
        int rMax = maxPathSumHelper(root->right, res);
        int op1 = root->val;
        int op2 = lMax + root->val;
        int op3 = rMax + root->val;
        int op4 = rMax + lMax + root->val;
        res = max({res, op1, op2, op3, op4});
        
        int retOp1 = root->val;
        int retOp2 = lMax + root->val;
        int retOp3 = rMax + root->val;
        return max({retOp1, retOp2, retOp3});
    }
public:
    int maxPathSum(TreeNode* root) {
        int res = INT_MIN;
        maxPathSumHelper(root, res);
        return res;
    }
};