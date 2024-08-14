// Link : https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/description/

/**
 * Definition for a binary tree node.
 * public class TreeNode {
 *     int val;
 *     TreeNode left;
 *     TreeNode right;
 *     TreeNode() {}
 *     TreeNode(int val) { this.val = val; }
 *     TreeNode(int val, TreeNode left, TreeNode right) {
 *         this.val = val;
 *         this.left = left;
 *         this.right = right;
 *     }
 * }
 */
class Solution {
    int curSum;
    
    Solution() {
        curSum = 0;
    }

    void bstToGstHelper(TreeNode cur) {
        if(cur == null)
            return;

        // Reverse in order traversal

        // Right Subtree
        bstToGstHelper(cur.right);

        // Tackle the cur node
        curSum += cur.val;
        cur.val = curSum;

        // Left Subtree
        bstToGstHelper(cur.left);
    }

    public TreeNode bstToGst(TreeNode root) {
        bstToGstHelper(root);
        return root;
    }
}