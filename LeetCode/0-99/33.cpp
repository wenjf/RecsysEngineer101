class Solution {
public:
    int search(vector<int>& nums, int target) {
        if(nums.size() < 1) return -1;
        int begin = 0;
        int end = nums.size() - 1;
        int mid = end / 2;
        while(nums[mid] != target&&(end - begin) > 1){
            if(nums[begin] < nums[mid]){
                if(nums[begin]<=target&&nums[mid]>=target){
                    end = mid;
                    mid = begin + (end - begin)/2;
                }else{
                    begin = mid + 1;
                    mid = begin + (end - begin)/2;
                }
            }
            else{
                if(nums[mid+1]<=target&&nums[end]>=target){
                    begin = mid + 1;
                    mid = begin + (end - begin)/2;
                }else{
                    end = mid;
                    mid = begin + (end - begin)/2;
                }
            }
        }
        if(nums[mid] == target)
            return mid;
        else if(nums[end] == target)
            return end;
        else
            return -1;
    }
};