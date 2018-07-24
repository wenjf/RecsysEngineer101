/*
这道题的关键点在于，证明这个解是O(N)的
*/

class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int start = 0; 
        int min_len = INT_MAX;
        int sum = 0;
        for(int i = 0 ; i< nums.size(); ++i){
            sum += nums[i];
            while(sum >= s){
                min_len = min(min_len, i - start + 1);
                sum -= nums[start++];
            }
        }
        return min_len == INT_MAX ? 0 : min_len;
        
    }
};