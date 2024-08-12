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

// Link : https://leetcode.com/problems/binary-tree-level-order-traversal/

class Solution {
    public List<List<Integer>> levelOrder(TreeNode root) {
        List<List<Integer> > ans = new ArrayList<>();

        if(root == null) // If empty, return right away.
            return ans;

        List<TreeNode> curLevel = new ArrayList<>(); // Will put nodes in this level-by-level.
        curLevel.add(root); // Starting with the root level.
        
        while(!curLevel.isEmpty()) {

            // First, let's add the current level to our answer
            List<Integer> curLevelVals = new ArrayList<>();
            for(TreeNode cur : curLevel)
                curLevelVals.add(cur.val);
            ans.add(curLevelVals);

            // Now, we'll use the nodes of the current level,
            // to get the nodes of the next level.
            List<TreeNode> nextLevel = new ArrayList<>();

            curLevel.forEach((curNode) -> {
                if(curNode.left != null)
                    nextLevel.add(curNode.left);
                if(curNode.right != null)
                    nextLevel.add(curNode.right);
            });

            // Move to the next level
            // by making curLevel = nextLevel
            curLevel = new ArrayList<>(nextLevel);
        }

        return ans;
    }
}