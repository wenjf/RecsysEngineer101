/*
二分搜索的综合性题目；难点在于判断第一个和最后一个；
*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size()==0)
            return vector<int>(2, -1);
        vector<int> res;
        int l = 0;
        int r = nums.size()-1;
        int m = (r - l) / 2 + l;
        //find first
        while(r-l>1){
            //第一个target确定在后半段；
            if(nums[m]<target){
                l = m+1;
            }
            //第一个target确定在前半段；nums[m]>=target, 也可能就是m
            else{
                r = m;
            }
            m = (r - l) / 2 + l;
        }
        if(nums[l] == target){
            res.push_back(l);
        }
        else if(nums[r] == target){
            res.push_back(r);
        }
        else{
            res.push_back(-1);
            res.push_back(-1);
            return res;
        }
        //find last
        l = 0;
        r = nums.size()-1;
        m = (r - l) / 2 + l;
        while(r-l>1){
            //最后一个target确定在后半段；
            if(nums[m]<=target){
                l = m;
            }
            //最后一个target确定在前半段；
            else{
                r = m;
            }
            m = (r - l) / 2 + l;
        }
        if(nums[r] == target){
            res.push_back(r);
        }
        else if(nums[l] == target){
            res.push_back(l);
        }
        return res;
    }
};