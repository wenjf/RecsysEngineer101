class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for(int i = 0; i < nums.size(); ++i){
            int value_current = nums[i];
            int front = i + 1;
            int back = nums.size() - 1;
            while(front <back){
                int value_front = nums[front];
                int value_back = nums[back];
                int temp = value_front + value_back + value_current;
                if( temp >0 ){
                    --back;
                }
                else if(temp <0){
                    ++front;
                }else{
                    vector<int> one_res{value_current, value_front, value_back};
                    res.push_back(one_res);
                    while(front< back&& nums[front] == value_front) front ++;
                    while(front< back&& nums[back] == value_back) back --;
                } 
            }
            while (i + 1 < nums.size() && nums[i + 1] == nums[i]) 
                i++;
            
        }
        return res;
    }
};