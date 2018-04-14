/*

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
    bool isBalanced(TreeNode* root) {
        if(!root) return true;
        int h_l = get_height(root->left);
        int h_r = get_height(root->right);
        if(abs(h_l - h_r)>1)
            return false;
        else
            return isBalanced(root->left)&&isBalanced(root->right);
        
    }
    
    int get_height(TreeNode* root){
        if(!root) return 0;
        int h_l = get_height(root->left);
        int h_r = get_height(root->right);
        return max(h_l, h_r) + 1;
    }
};