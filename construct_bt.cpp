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
    TreeNode* buildTreeHelper(vector<int>& preorder, vector<int>& inorder, int ps, int pe, int is, int ie) {
        if(ps > pe || is > ie) return NULL;
        int rootElement = preorder[ps];
        TreeNode* root = new TreeNode(rootElement);

        int nodeCountLeft = 0;
        int i = is;
        while(inorder[i] != rootElement) {
            nodeCountLeft++;
            i++;
        }
        // inorder range for the leftsubtree is from "is" "i-1"
        // inorder range for the rightsubtree is from "i+1" to "ie"
        // preorder range for the leftsubtree is from "ps+1" to "ps+nodeCountLeft"
        // preorder range for the rightsubtree is from "ps+nodeCountLeft+1" to "pe"
        int lst_is = is, lst_ie = i - 1;
        int rst_is = i + 1, rst_ie = ie;
        int lst_ps = ps + 1, lst_pe = ps + nodeCountLeft;
        int rst_ps = ps + nodeCountLeft + 1, rst_pe = pe;

        root->left = buildTreeHelper(preorder, inorder, lst_ps, lst_pe, lst_is, lst_ie);
        root->right = buildTreeHelper(preorder, inorder, rst_ps, rst_pe, rst_is, rst_ie);
        return root;

    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTreeHelper(preorder, inorder, 0, preorder.size() - 1, 0 , inorder.size() - 1);

    }
};