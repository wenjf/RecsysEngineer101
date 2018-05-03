//经典的回溯法题目之一

class Solution {
public:
	//begin 从数组的下标开始弄起
	//n nums的长度
	//k subset的长度
    void get_combine(int begin, int n, int k, vector<vector<int>>& res, vector<int>& one_res, vector<int>& nums){
        if(k == 0){
            res.push_back(one_res);
            return;
        }
        for(int i = begin; i < n - k+1 ;++i){
            one_res.push_back(nums[i]);
            get_combine(i+1, n, k-1, res, one_res, nums);
            one_res.pop_back();
        }   
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        for(int i = 0; i<=nums.size();++i){
            vector<int> temp;
            get_combine(0, nums.size(), i, res, temp, nums);
        }
        return res;
    }
};