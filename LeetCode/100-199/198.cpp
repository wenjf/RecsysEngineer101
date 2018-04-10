/*
绝不可能会出现连续两个位置都不偷的情况；
所以dp[i] = max(dp[i-2] + nums[i], dp[i-1])
*/


class Solution {
public:
    int rob(vector<int>& nums) {
        int total_num = nums.size();
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        int* dp = (int*)malloc(sizeof(int)*total_num);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for(int i = 2; i<total_num; ++i){
            int temp_1 = dp[i-1];
            int temp_2 = dp[i-2] + nums[i];
            dp[i] = max(temp_1, temp_2);
        }
        int res = dp[total_num-1];
        free(dp);
        return res;
    }
};