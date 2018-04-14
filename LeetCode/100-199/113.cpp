/*
简单的深度优先搜索
回溯法
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        vector<int> temp;
        if(!root) 
            return res;
        temp.push_back(root->val);
        check_sum(root, sum - root->val, temp, res);
        return res;
        
    }
    
    void check_sum(TreeNode* root, int sum, vector<int>& temp, vector<vector<int>>& res){
        if(!root){
            return;            
        }
        if(sum==0&&!root->left&&!root->right){
            res.push_back(temp);
            return;
        }
        if(root->left){
            temp.push_back(root->left->val);
            check_sum(root->left, sum - root->left->val, temp, res);        
            temp.pop_back();
        }
        if(root->right){
            temp.push_back(root->right->val);
            check_sum(root->right, sum - root->right->val, temp, res);        
            temp.pop_back();
        }
    }
};