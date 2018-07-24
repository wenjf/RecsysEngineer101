/*
也是经典的递归题目
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
    int maxPathSum(TreeNode* root) {
        int res = -99999;
        GetRootContainedMax(root, res);
        return res;
    }
    
    int GetRootContainedMax(TreeNode* root, int& res){
        if(root==NULL)
            return 0;
        int l = GetRootContainedMax(root->left, res);
        int r = GetRootContainedMax(root->right, res);
        int local_max = root->val;
        local_max += l>0? l:0;
        local_max += r>0? r:0;
        res = max(local_max, res);
        return root->val+max(l>0? l:0, r>0? r:0);
    }
};