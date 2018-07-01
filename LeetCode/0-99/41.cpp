//另外一个需要弄清楚的地方就是：引用传值是否能改变nums本身？不然的话怎么进行原址的search？
//不过考虑到参数没有加const，所以认为可以改变。

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size ; ++i)
            //如果nums[i]属于[1, size]；那么nums[i]应该在 nums[i] -1 这个位置上
            while(nums[i]>0&&nums[i]<=size&&nums[i] != nums[nums[i] - 1])
                swap(nums[i], nums[nums[i] - 1]);
        //难点在于，证明上面这个两层循环是O(n)的：
        //关键点：需要理解，每一个元素最多被访问两次，所以是2N的复杂度
        for(int i = 0; i < size; ++i)
            if(nums[i] != i+1)
                return i+1;
        return size+1;
    }
};