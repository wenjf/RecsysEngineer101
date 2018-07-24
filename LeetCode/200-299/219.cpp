/*
因为要判断有没有间隔小于等于k的重复数字，所以hash中每次存最近的一次某个数字；对应下面的15行
*/

class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        if(nums.size() == 0) return false;
        unordered_map<int, int> h;
        for(int i = 0; i < nums.size(); ++i){
            if(h.find(nums[i])!=h.end()){
                if(i - h[nums[i]] <= k)
                    return true;
            }
                h[nums[i]] = i;
        }
        return false;
    }
};