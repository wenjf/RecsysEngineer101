//参考爬楼梯那题，斐波拉契数列

class Solution {
public:
    int numDecodings(string s) {
        if(s.size() == 0)
            return 1;
        if(s[0] == '0')
            return 0;
        int pre_pre;
        int pre = 1;
        int res = 1;
        for(int i = 1; i< s.size(); ++i){
            pre_pre = pre;
            pre = res;
            res = 0;
            if(s[i] != '0')
                res += pre;
            if(s[i-1]=='1'||(s[i-1]=='2'&&s[i]<='6'))
                res += pre_pre;
        }
        return res;
        
    }
};