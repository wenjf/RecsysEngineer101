/*
get_combine: 从begin 到 n，取K个数字出来；
递归的调用；
回溯法的经典题目
*/

void get_combine(int begin, int n, int k, vector<vector<int>>& res, vector<int>& one_res){
	if(k == 0){
		res.push_back(one_res);
		return;
	}
	for(int i = begin; i<= n - k+1 ;++i){
		one_res.push_back(i);
		get_combine(i+1, n, k-1, res, one_res);
		one_res.pop_back();
	}
}


class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> one_res;
        get_combine(1, n, k, res, one_res);
        return res;
    }
};