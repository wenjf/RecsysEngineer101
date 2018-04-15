/*
一道有趣的DP
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
    vector<TreeNode*> generateTrees(int n) {
        unordered_map<int, unordered_map<int, vector<TreeNode*>>> dp;
        if(n == 0) return vector<TreeNode*>();
        for(int root = 1; root <= n ; ++root){
            TreeNode* single = new TreeNode(root);
            dp[root][root].push_back(single);
        }
        for(int len = 2; len <= n; ++len){
            for(int begin = 1; begin + len - 1 <= n; ++begin){
                vector<TreeNode*> res;
                for(int root = begin;root <= begin+len - 1; ++root){
                    if(root>begin&&root<begin+len - 1){
                        for(auto iter_l = dp[begin][root-1].begin(); iter_l!=dp[begin][root-1].end(); iter_l++){
                            for(auto iter_r = dp[root+1][begin+len-1].begin(); iter_r!=dp[root+1][begin+len-1].end(); iter_r++){
                                TreeNode* root_node = new TreeNode(root);
                                root_node->left = *iter_l;
                                root_node->right = *iter_r;
                                res.push_back(root_node);
                            }
                        }
                    }
                    else if(root<begin+len - 1){
                        for(auto iter = dp[root+1][begin+len-1].begin(); iter!=dp[root+1][begin+len-1].end();iter++){
                            TreeNode* root_node = new TreeNode(root);
                            root_node->right = *iter;
                            res.push_back(root_node);
                        }
                    }
                    else{
                        for(auto iter = dp[begin][root-1].begin(); iter!=dp[begin][root-1].end(); iter++){
                            TreeNode* root_node = new TreeNode(root);
                            root_node->left = *iter;
                            res.push_back(root_node);
                        }
                    }
                }
                dp[begin][begin+len - 1] = res;
            }
        }
        return dp[1][n];
        
    }
};