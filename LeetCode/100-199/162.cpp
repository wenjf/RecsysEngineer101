/*
分解所有的可能性；这样就找到reduce问题规模的方法。
适合考应届生；
*/

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        return RecusFindPeak(nums, 0, nums.size()-1);
    }
    
    int RecusFindPeak(vector<int>& nums, int start, int end){
        if(start==end)
            return start;
        if(start+1 == end)
            return nums[start]>nums[end]? start:end;
        int mid = (end - start) / 2 + start;
        if(nums[mid]<nums[mid+1])
            return RecusFindPeak(nums, mid+1, end);
        if(nums[mid]<nums[mid-1])
            return RecusFindPeak(nums, start, mid-1);
        return mid;
    }
};