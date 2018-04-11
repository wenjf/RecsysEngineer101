/*
Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

For example:
A = [2,3,1,1,4], return true.

A = [3,2,1,0,4], return false.
*/


/*
贪心法；只需要记录目前能最大达到的位置即可覆盖所有情况了；很巧妙
*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reach = 0;
        int i ;
        for( i = 0; i< nums.size()&& i <=reach; ++i)
            reach = max(reach, i +nums[i]);
        return i == nums.size();
    }
};