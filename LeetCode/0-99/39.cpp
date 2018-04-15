/*
简单的回溯法
*/

class Solution {
public:
    void get_next(vector<int>& candidates, int begin, int target, vector<int>& temp, vector<vector<int>>& res){
        if(target == 0){
            res.push_back(temp);
            return;
        }
        if(begin >= candidates.size()||target<0)
            return;
        for(int i = begin; i <candidates.size(); ++i){
            temp.push_back(candidates[i]);
            get_next(candidates, i, target - candidates[i], temp, res);
            temp.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> temp;
        get_next(candidates, 0, target, temp, res);
        return res;
    }
};