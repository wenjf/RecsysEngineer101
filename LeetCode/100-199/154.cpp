class Solution {
public:
    int findMin(vector<int>& nums) {
        int start = 0;
        int end = nums.size() - 1;
        int mid = (end - start) / 2 + start;
        while(end - start > 1){
            while(nums[start]==nums[mid]&&nums[mid]==nums[end]&&end - start > 1){
                --end;
                ++start;
            }
            //确定在前半段
            if(nums[mid]<=nums[end]){
                end = mid;
                mid = (end - start) / 2 + start;
            }
            else if(nums[start]<=nums[mid]){
                start = mid+1;
                mid = (end - start) / 2 + start;
            }
            //确定在后半段
        }
        return min(nums[start], nums[end]);
        
    }
};