/*
实际上是一个preorder 
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
    void flatten(TreeNode* root) {
        if(!root) return;
        vector<TreeNode*> s;
        TreeNode* curr = root;

        while(curr){
            if(curr->right)
                s.push_back(curr->right);
            if(curr->left){              
                //std::cout << curr->val << std::endl;
                curr->right = curr->left;
                curr->left = NULL;
                curr = curr->right;
            }
            else{
                if(s.size()){
                    curr->right = s.back();
                    s.pop_back();
                    //std::cout << curr->val << std::endl;
                    curr = curr->right;
                }
                else
                    curr = NULL;
            }
        }
    }
};