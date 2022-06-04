/*
关键的观察：
1. 每个元素都有可能会做窗口内的最大
2. 在同一个窗口内，如果i < j 而且 nums[i] < nums[j]，那么nums[i]不可能成为最大

我们维护一个单调递减的队列，队列最多覆盖k窗口内的数，每次一个num入队时，把队列中比自己小的全部干掉即可
*/
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        deque<int> q;
        vector<int> res;
        for(int i =0 ;i < nums.size(); ++i){
            while(q.size() && q.front()<(i-k+1)){
                q.pop_front();
            }
            while(q.size() && nums[q.back()] < nums[i]){
                q.pop_back();
            }
            q.push_back(i);
            if(i>=k-1){
                res.push_back(nums[q.front()]);       
            }
        }
        return res;
    }
};