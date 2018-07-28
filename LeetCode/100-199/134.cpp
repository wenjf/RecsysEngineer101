/*
如何判断是否存在这样的位置？
sum(gas) > sum(total)
怎么找到呢？

只能说 这个解法还是巧妙
*/

class Solution {
public
    int canCompleteCircuit(vectorint& gas, vectorint& cost) {
        int cusum = 0, total_sum = 0;
        int start = 0;
        for(int i = 0 ; i gas.size(); ++i){
            int rest_here = gas[i] - cost[i];
            total_sum += rest_here;
            cusum += rest_here;
            if(cusum  0){
                start = i+1;
                cusum = 0;                
            }
        }
        if(total_sum  0)
            return -1;
        return start;
    }
};