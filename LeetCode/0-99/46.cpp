/*
Given a collection of distinct numbers, return all possible permutations.

For example,
[1,2,3] have the following permutations:
[
  [1,2,3],
  [1,3,2],
  [2,1,3],
  [2,3,1],
  [3,1,2],
  [3,2,1]
]
*/

/*
递归解决，
n个数字的全排列为：
依次把每一个数字固定在第一个位置，剩下的n-1个数字全排列；
以下的递归实现理解为DFS，也是回溯法。
*/



void permute_all(vector<int>& nums, int begin, vector<vector<int>>& res){
    if(begin >= nums.size()-1){
        res.push_back(nums);
        return;
    }
    for(int i = begin; i<nums.size(); ++i){
        swap(nums[begin],nums[i]);
        permute_all(nums, begin+1, res);
        swap(nums[i],nums[begin]);
    }
}

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        permute_all(nums, 0, res);
        return res;
    }
};