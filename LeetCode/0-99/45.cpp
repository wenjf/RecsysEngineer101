/*
need revisit
*/

class Solution {
public:
    int jump(vector<int>& nums) {
        //greedy: 记录跳i步时，能够到达的范围；
        //那么第i+1步时能到达的范围就是，i步的范围内的坐标+对应的步数
        if(nums.size() < 2)
            return 0;
        int mi = 0, ma = 0;
        int i = 0;
        for(; i < nums.size(); ++i){
            int new_mi = mi, new_ma = ma;
            for(int j = mi; j<=ma; ++j){
                new_mi = min(new_mi + 1,  j + nums[j]);
                new_ma = max(new_ma, j + nums[j]);
                if(new_ma >= nums.size() -1 )
                    return i + 1;
            }
            mi = new_mi;
            ma = new_ma;
        }
    }
};