/*
排序以后，
1. 要允许在candidate中不同位置的相同数字出现在结果vector中的不同位置；
2. 不能允许在candidate中不同位置的相通数字出现在结果vector中的相通位置；
*/
class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        for(auto i : candidates){
            // std::cout << i << std::endl;
        }
        vector<int> temp;
        vector<vector<int>>res;
        ValideCombination(candidates, 0, target, temp, res);
        return res;
    }
    
    void ValideCombination(vector<int>& candidates, int start, int local_target, vector<int>& temp, vector<vector<int>>& res){
        if(local_target == 0){
            res.push_back(temp);
            return;
        }
        //pruning
        if(local_target < 0)
            return;
        for(int i = start; i < candidates.size(); ++i){
            // std::cout << candidates[i]==candidates[i-1] ? "Yes":"???" << std::endl;
            //这里特殊case的处理非常巧妙,对应前面的第2点
            if(i>start&&candidates[i]==candidates[i-1]) 
                continue; 
            temp.push_back(candidates[i]);
            // local_target -=  candidates[i];
            ValideCombination(candidates, i+1, local_target -  candidates[i], temp, res);
            temp.pop_back();
        }
    }
};