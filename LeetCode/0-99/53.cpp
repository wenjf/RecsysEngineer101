/*
和121 本质上同一个题目；求策略的最大回撤时可以用121题的算法；
*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        int max;
        vector<int> dp(nums.size(), 0);
        dp[0] = nums[0];
        max = nums[0];
        for(int i = 1 ;i< nums.size(); ++i){
            dp[i] = dp[i-1] > 0 ? (nums[i] + dp[i-1]) :nums[i];
            if(dp[i] > max)
                max = dp[i];
        }
        return max;
    }
};