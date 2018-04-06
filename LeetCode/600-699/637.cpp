/*
* https://leetcode.com/problems/longest-univalue-path/description/
*/

/*
A very clear DFS solution
*/

/*
思路在于，递归的计算，
以当前节点为根，向左延展的最长path；
以当前节点为根，向右延展的最长path；
当前节点不是根节点，是path中的一员。
fucking awesome.
*/

class Solution {
public:
    int longestUnivaluePath(TreeNode* root) {
        int lup = 0;
        if (root) dfs(root, lup);
        return lup;
    }

private:
    int dfs(TreeNode* node, int& lup) {
        int l = node->left ? dfs(node->left, lup) : 0;
        int r = node->right ? dfs(node->right, lup) : 0;
        int resl = node->left && node->left->val == node->val ? l + 1 : 0;
        int resr = node->right && node->right->val == node->val ? r + 1 : 0;
        lup = max(lup, resl + resr);
        return max(resl, resr);
    }
};