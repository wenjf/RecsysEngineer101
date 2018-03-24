
/*
Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
*/

//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
S的最大回文子串，等于
    1：s[0] == s[-1]；s[1][-2]是回文串；则是s；
    2：s[0] ！= s[-1] 则是s[1][-2]的最大回文子串
显然，这是一个问题的答案依赖于更小规模问题的解的问题；所以采用动态规划求解；
使用自底向上的动态规划：
*/

class Solution {
public:
    string longestPalindrome(string s) {
        int begin = 0, end = 0, max = 1;
        int** is_palin = new int*[s.size()];
        for(int i=0;i<s.size();i++){
            is_palin[i] = new int[s.size()];
        }
        for(int i = 0 ;i <s.size(); ++i){
            for(int j = 0 ; j<s.size(); ++j){
                is_palin[i][j] = i==j ? 1:0;
            }
        }
        for(int l = 1; l <s.size();++l){
            for(int i = 0; i < s.size() - l; ++i ){
                if(s[i] == s[i+l]&&(is_palin[i+1][i+l-1]==1||l==1)){
                    is_palin[i][i+l] = 1;
                    if(max < l+1){
                        max = l+1;
                        begin = i;
                        end = i+l;
                    }
                }
            }
        }
        return s.substr(begin, max);
    }
};


//TODO： 这个解法效率只打败了11%的cpp解法，还需要进行一些细节上的优化。