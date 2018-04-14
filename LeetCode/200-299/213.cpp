/*
相比于house robber1， 首尾不能同时取。所以拆分为两个问题，0->n-1； 1->n；
*/

int robber(vector<int>& nums, int l, int r){
    int pre = 0, curr =0;
    for(int i = l;i<r;++i){
        int temp = max(pre+nums[i], curr);
        pre = curr;
        curr = temp;
    }
    return curr;
}

class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size()==0) return 0;
        if(nums.size()==1) return nums[0];
        return max(robber(nums, 0, nums.size()-1), robber(nums, 1, nums.size()));
        
    }
};