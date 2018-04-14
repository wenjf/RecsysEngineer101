//简单的广度优先搜索
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
    vector<vector<int>> levelOrder(TreeNode* root) {
               if(root == NULL) return vector<vector<int>>();
        vector<vector<int>> res;
        queue<TreeNode*> q;
        TreeNode* current = root;

        q.push(current);
        
        int last_num = 1;
        int i = 0;
        vector<int> one_res;
        while(q.size()>0){
            current = q.front();
            one_res.push_back(current->val);
            if(current->left)
                q.push(current->left);
            if(current->right)
                q.push(current->right);
            q.pop();
            ++i;
            if(i == last_num){
                last_num = q.size();
                i = 0;
                res.push_back(one_res);
                one_res.clear();
            }
        }
        return res;
             
    }
};

