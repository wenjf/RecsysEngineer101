/*
要存在这样的数必须满足：有升序的子序列；
要找到最小的这样的数：要找到最后一个升序的序列，然后其后面最小的数字放在这里；然后后面的子串再升序排列；
这个题目出的好，蕴含了不少思想。
*/

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int k  = - 1;
        int l = -1;
        for(int i = nums.size()-2; i>=0; --i){
            if(nums[i]<nums[i+1]){
                k = i;                
                break;
            }
        }
        if(k ==-1){
            reverse(nums.begin(), nums.end());
            return;
        }
        for(int i = nums.size()-1; i>k; --i){
            if(nums[i]>nums[k]){
                l = i;           
                break;
            }
        }
        swap(nums[k], nums[l]);
        reverse(nums.begin() + k + 1, nums.end());
        return ;
    }
};