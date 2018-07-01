//较矮的那一侧是限制max water的瓶颈，所以要移动他
//two point 从两边开始往中间扫描的思路，marked

class Solution {
public:
    int maxArea(vector<int>& height) {
        int s = 0, e= height.size()-1;//s for start, e for end
        int res = 0;
        while(s<e){
            int water = min(height[s], height[e]);
            int len = e - s;
            res = max(res, water*len);
            while(height[s]<=water&&s<e) ++s;
            while(height[e]<=water&&s<e) --e;
        }
        return res;
    }
};