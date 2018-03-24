class Solution {
public:
    int maxCount(int m, int n, vector<vector<int>>& ops) {
        if(ops.size() == 0)
            return m*n;
        int min_a, min_b;
        min_a = 99999;
        min_b = 99999;
        for(auto iter = ops.begin();iter !=ops.end();iter++){
            if((*iter)[0]<min_a)
                min_a = (*iter)[0];
            if((*iter)[1]<min_b)
                min_b = (*iter)[1];
        }
        return min_a*min_b;
    }
};