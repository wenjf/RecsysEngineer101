/*
Given a string, find the length of the longest substring without repeating characters.

Examples:

Given "abcabcbb", the answer is "abc", which the length is 3.

Given "bbbbb", the answer is "b", with the length of 1.

Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/


//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
难点在于如何记录每个字符出现的位置；

解析： 对于一个当前没有重复字符的串，当下一个字符上一次出现的位置，在当前字符中，字符串失去要求的性质(without repeating characters)；
       此时，新的 substring without repeating characters则从当前字符上一次出现的位置的下一个开始。
*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int cct_position[128];
        for(int i = 0; i < 128; ++i){
            cct_position[i] = -1;
        }
        int begin = 0;
        int end = 0;
        int max = 0;
        while(end < s.size()){
            if(cct_position[s[end] - ' ']<begin){
                if(max < end - begin + 1)
                    max = end - begin + 1;
                //cout << end << "\t" << begin<< endl;
            }
            else{
                begin = cct_position[s[end] - ' '] + 1;
            }
            cct_position[s[end] - ' '] = end;//新出现的字符不要忘记记录其位置
            ++end;
        }
        return max;
        
    }
};