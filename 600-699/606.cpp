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
    string tree2str(TreeNode* t) {
        std::string res;
        if (t == NULL)
            return "";
        std::stringstream temp;
        temp << t->val;
        res = temp.str();

        if(t->left !=NULL || t->right !=NULL ){
            if(t->left == NULL)
                res += "()";
            else
                res += "(" + tree2str(t->left) + ")";
            if(t->right != NULL)
                res += "(" + tree2str(t->right) + ")";
            
        }
        return res;
    }
};