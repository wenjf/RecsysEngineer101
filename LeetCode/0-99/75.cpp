/*
 updated 20220509: 对于 low：下一个0应该放的位置，mid：我已经处理过的位置，high：下一个2应该放的位置
*/
class Solution {
    public:
    void sortColors(vector<int>& nums) 
    {
        int tmp = 0, low = 0, mid = 0, high = nums.size() - 1;
    
        while(mid <= high)
        {
            if(nums[mid] == 0)
            {
                tmp = nums[low];
                nums[low] = nums[mid];
                nums[mid] = tmp;
                low++;
                mid++; // 为什么对于0，mid++，但是对于下面的==2的情况，mid不进行++呢？尝试分析这一点
            }
            else if(nums[mid] == 1)
            {
                mid++;
            }
            else if(nums[mid] == 2)
            {
                tmp = nums[high];
                nums[high] = nums[mid];
                nums[mid] = tmp;
                high--;
            }
        }
    }
};