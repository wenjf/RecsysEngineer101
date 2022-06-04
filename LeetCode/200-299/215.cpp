class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int l = 0, r = nums.size() - 1;
        while(l<r){
            int res = helper(nums, l, r);
            if(res == k-1)
                break;
            if(res > k-1){
                r = res-1;
            } else{
                l = res + 1;
            }
        }
        return nums[k-1];
    }
    
    int helper(vector<int> & nums, int l, int r){
        if(l>=r){
            return l;
        }
        int m = (l+r)>> 1;
        int pivot = nums[m];
        swap(nums[m], nums[r]);
        int nextIdx = l-1;
        for(int i = l; i < r; ++i){
            if(nums[i] >= pivot){
                swap(nums[i], nums[++nextIdx]);
            }
        }
        swap(nums[r], nums[++nextIdx]);
        return nextIdx;
    }
};