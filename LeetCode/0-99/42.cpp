class Solution {
public:
    int trap(vector<int>& height) {
        if(height.size() <=2)
            return 0;
        int l = 0, r = 1;
        int low;
        int res = 0;
        //循环不变量，除了right = height.size() -1 时，right总是left->right区间最高的
        while(r<height.size()){
            int temp_sum = 0;
            while(r<height.size()&&height[r]<height[l]){
                temp_sum += height[r];
                ++r;
            }
            //如果是因为r遍历完成以后结束，退回到最右位置
            if(r==height.size())
                break;
            //计算当前总的蓄水量
            int len = r- l - 1;
            int low = min(height[r], height[l]);
            temp_sum = low * len - temp_sum;
            temp_sum = max(0, temp_sum);
            res+= temp_sum;
            
            l = r;vcc
            ++r;
        }
        int mid = l;
        r= height.size() - 1;
        l = r - 1;
        while(l>=mid){
            int temp_sum = 0;
            while(l>=mid&&height[l]<height[r]){
                temp_sum += height[l];
                --l;
            }
            //如果是因为r遍历完成以后结束，退回到最右位置
            if(l<mid)
                break;
            //计算当前总的蓄水量
            int len = r- l - 1;
            int low = min(height[r], height[l]);
            temp_sum = low * len - temp_sum;
            temp_sum = max(0, temp_sum);
            res+= temp_sum;
            
            r= l;
            --l;
        }
        return res;
    }
};

//改进思路：
//从左往右递增无法存水；
//从右往左递增无法存水;
//如果在一次循环里面解决，就要决定每次移动较矮的那个；为什么？ -> 假如目前的left 和 right 就是一个容器的两个边，那么决定能装多少水的应该是较矮的那一边，所以要从这一侧开始移动；
//所以其实是分割为了三个容器: 0 ->left_max, left_max->right_max, right_max-> end；同时要防止left_max 和 right_max 交叉；
