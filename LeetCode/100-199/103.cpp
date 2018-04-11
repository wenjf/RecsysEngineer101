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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root== NULL) return vector<vector<int>>();
        bool l2r = true;
        vector<vector<int>> res;
        vector<TreeNode*> s;
        s.push_back(root);
        while(s.size()>0){
            vector<TreeNode*> temp_s;
            vector<int> temp;
            while(s.size()){
                TreeNode* top = s.back();
                s.pop_back();
                temp.push_back(top->val);
                if(l2r){
                    if(top->left!=NULL)
                        temp_s.push_back(top->left);
                    if(top->right!=NULL)
                        temp_s.push_back(top->right);
                }
                else{
                    if(top->right!=NULL)
                        temp_s.push_back(top->right);    
                    if(top->left!=NULL)
                        temp_s.push_back(top->left);
                }
            }
            l2r = !l2r;
            s = temp_s;
            res.push_back(temp);
        }
        return res;
        
    }
};