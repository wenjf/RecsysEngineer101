/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.
*/

/*
二分搜索，难点在于判断条件；
*/


class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0] < nums.back())
            return nums[0];
        int begin = 0;
        int end = nums.size() - 1;
        int mid = end / 2;
        while(end - begin > 1){
            if(nums[begin] < nums[mid]){
                begin = mid;
                mid = begin + (end - begin) /2;
            }
            else{
                end = mid;
                mid = begin + (end - begin) /2; 
            }
        }
        if(nums[begin] > nums[end])
            return nums[end];
        else
            return nums[begin];
        
    }
};