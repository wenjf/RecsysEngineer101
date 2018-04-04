/*
Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") → false
isMatch("aa","aa") → true
isMatch("aaa","aa") → false
isMatch("aa", "*") → true
isMatch("aa", "a*") → true
isMatch("ab", "?*") → true
isMatch("aab", "c*a*b") → false
*/

/*

状态转移：
dp[i][j]
1: s[i-1] == p[j-1] && dp[i-1][j-1] == 1
2: p[j-1] == ? && && dp[i-1][j-1] == 1
3: p[j-1] == * -> dp[i-1][j-1] == 1
4：p[j-1] != s[i-1] 但是 dp[i][j-1] =1 && 上一个字符是*

注意边界条件；
*/


class Solution {
public:
    bool isMatch(string s, string p) {
    	int **dp;
    	int s_size = s.size();
    	int p_size = p.size();
    	dp = (int**)malloc(sizeof(int*)*(s_size+1));
    	for(int i = 0;i <= s.size(); ++i)
    		dp[i] = (int*)malloc(sizeof(int)*(p_size+1));
    	//init dp 
        for(int i = 0; i <= s_size; ++i){
        	for(int j = 0; j <= p_size; ++j){
        		dp[i][j] = 0;
        	}
        }
        dp[0][0] = 1;
        if(p.size()>0&&p[0] - '*' == 0){
            for(int i = 0; i<=s.size(); ++i)
                dp[i][1] = 1;
        }
    			
        for(int i = 0; i <= s_size; ++i){
        	for(int j = 1; j <= p_size; ++j){
        		if(p[j-1] - '*' == 0){
        			if(i-1>=0&&dp[i-1][j-1] == 1){
        				dp[i][j] = 1;
        			}
        			else if(i-1>=0&&dp[i-1][j] == 1){
        				dp[i][j] = 1;

        			}
        			else if(dp[i][j-1] == 1){
        				dp[i][j] = 1;        				
        			}   

        		}
        		else if(i-1>=0&&(p[j -1 ]-s[i-1] == 0||p[j-1]-'?' ==0)&&(dp[i-1][j-1]==1)){
        			dp[i][j] = 1;
        		}
        	}
        }

        bool res = dp[s_size][p_size] == 1 ? true:false;
        for(int i = 0;i <=s_size; ++i)
    		free(dp[i]);
    	free(dp);
    	return res;
    }
};