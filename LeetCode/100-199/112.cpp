/*
关键在于叶节点的定义；也就是下面代码中return ture的地方。
*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(root==NULL)
            return false;
        if(root->val == sum&&!root->left&&!root->right) 
            return true;
        int new_sum = sum - root->val;
        return hasPathSum(root->left, new_sum)||hasPathSum(root->right, new_sum);
        
    }
};