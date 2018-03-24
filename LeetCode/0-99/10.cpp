/*

'.' Matches any single character.
'*' Matches zero or more of the preceding element.

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "a*") → true
isMatch("aa", ".*") → true
isMatch("ab", ".*") → true
isMatch("aab", "c*a*b") → true
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------
/*
难点在于，*出现后，前面的字符可以被匹配0次，1次，或者多次。
由于这一点，可能出现，
s.substr(0, s.size()-1) 和 p能匹配，而且s和p也能匹配；  
s和p.substr(0, p.size()-1)能匹配，s和p也能匹配等等情况；那么s和p能否匹配就能通过 s 和 p 的一些子串能否匹配再加上一些限制条件加以判断；这就是构成了一个动态规划的问题。
从而考虑动态规划来解决这个问题
记为： dp[i][j] = 从s的开头到s的第i-1个字符为止(包括)，从p的开头到p的第j-1个字符为止(包括)；能否匹配；(为什么要-1，考虑遇到空串的情况，下面的解释有说)
状态转移方程：考虑 p[j] == '*'时，前面的字符匹配0次，1次，多次的情况。
dp[i][j] 就可以从
    遇到*号：dp[i-1][j]   dp[i][j-1]  dp[i][j-2]
    没有遇到*号：dp[i-1][j-1]
得到；
另外，考虑到空串和空串也能匹配上，那么将 dp[0][0]记为遇到空串时的情况；
就需要初始化dp状态数组；
*/


bool is_character_match(char c, char p){
    if(p-'.' == 0 || c - p ==0 )
        return true;
    return false;
}

class Solution {
public:
    bool isMatch(string s, string p) {
        if(p.size()==0) return s.size()==0;
        int is_match[s.size()+1][p.size()+1];
        for(int i = 0; i<=s.size();i++){
            for(int j = 0; j<=p.size();j++)
                is_match[i][j] = 0;
        }
        is_match[0][0] = 1;
        if(p.size()>=2&&p[1]-'*'==0)
            is_match[0][2] = 1;
        for(int i = 0; i<s.size()+1;i++){
            for(int j = 1; j<p.size()+1;j++){                
                //*号的情况
                if(p[j-1] - '*' == 0){
                    //*号匹配多次
                    if(i-1>0){
                        if(is_match[i-1][j]==1&&is_character_match(s[i-1], p[j-2]))
                            is_match[i][j]=1;
                    }
                    //*号匹配第一次
                    if(j-1>0){
                        if(is_match[i][j-1]==1)
                            is_match[i][j]=1;
                    }
                    //*号匹配0次
                    if(j-2>=0){
                        if(is_match[i][j-2]==1)
                            is_match[i][j] = 1;
                    }
                }
                //非*号
                else if(i-1>=0&&j-1>=0){
                    if(is_match[i-1][j-1]==1&&is_character_match(s[i-1], p[j-1]))
                        is_match[i][j] = 1;
                }
            }
        }
        return is_match[s.size()][p.size()] == 1;
    }
};