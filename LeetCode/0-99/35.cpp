class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        if(nums[0] > target) return 0;
        if(nums[nums.size()-1] < target) return nums.size();
        int begin = 0;
        int end = nums.size() - 1;
        int mid = (end>>1) + begin;
        while(end - begin >= 2){
            if(nums[mid] > target){
                end = mid;
            }
            else{
                begin = mid;
            }
            mid = ((end - begin)>> 1)  + begin;
        }
        if(nums[begin] >= target){
            return begin;
        }
        else{
            return end;
        }
    }
};