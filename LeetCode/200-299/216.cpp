//比combination1 2 都要简单

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> temp;
        ValideCombination(temp, 1, k, res, n);
        return res;
    }
    
    void ValideCombination(vector<int>& temp, int begin_num, int rest_k, vector<vector<int>>& res, int target){
        if(target<0){
            return;
        }
        if(target == 0 && rest_k == 0){
            res.push_back(temp);
        }
        for(int i = begin_num; i < 10; ++i){
            temp.push_back(i);
            ValideCombination(temp, i+1, rest_k-1, res, target - i);
            temp.pop_back();
        }
    }
};