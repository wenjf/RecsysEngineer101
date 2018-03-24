
// * Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 };
 

//  首先使用递归版本来实现：
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> res;
        if(root != NULL)
            res.push_back(root->val);
        std::vector<int> temp = preorderTraversal(root->left);
        res.insert(res.end(), temp.begin());
        temp = preorderTraversal(root->right);
        res.insert(res.end(), temp.begin());
        return res;
    }
};

 /*
    使用栈来模拟递归操作
    那么栈中每加入一个元素代表依次递归版本下的函数调用；
    而根据递归的几个原则：
        1. 定义结束条件
        2.
    因此压栈前验证是否结束；
    当函数中调用自己的语句完成后，则需要出栈。

*/

class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        TreeNode* curr = root;
        vector<int> res;
        vector<TreeNode*> s;
        while(s.size()||curr!=NULL){
            while(curr!=NULL){
                s.push_back(curr);
                res.push_back(curr->val);
                curr = curr->left;
            }
            curr = s.back();
            s.pop_back();
            curr = curr->right;
        }
        return res;
    }
};