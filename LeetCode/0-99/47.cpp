/*
Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[
  [1,1,2],
  [1,2,1],
  [2,1,1]
]
*/



/*
相比于46题，多了一个可能重复的情况。
全排列为：
依次把不同的数字放在第一个，再加上n-1个数字的全排列就是结果了。
用一个hash set判断一个数字是否放在了第一个位置
*/



void permuteUnique_all(vector<int>& nums, int begin, vector<vector<int>>& res){
    if(begin == nums.size()-1){
        res.push_back(nums);
        return;
    }
    unordered_set<int> is_used;
    for(int i = begin; i< nums.size();++i){
        if(is_used.find(nums[i])==is_used.end()){
            is_used.insert(nums[i]);
            swap(nums[begin], nums[i]);
            permuteUnique_all(nums, begin+1, res);
            swap(nums[i], nums[begin]);
        }
    }
}

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>> res;
        permuteUnique_all(nums, 0, res);
        return res;
    }
};