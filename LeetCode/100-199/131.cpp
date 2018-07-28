/*
具体没有想到用回溯法，哎呀，有点虚
*/

class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        vector<string> temp;
        PartitionString(res, temp, s, 0);
        return res;
    }
    
    void PartitionString(vector<vector<string>>& res, vector<string>&temp, string& s, int start){
        if(start >=s.size()){
            res.push_back(temp);
        }
        for(int i = start; i < s.size(); i++){
            if(IsPalindrome(s, start, i)){
                temp.push_back(s.substr(start, i - start + 1));
                PartitionString(res, temp, s, i+1);
                temp.pop_back();
            }
        }
    }
    
    bool IsPalindrome(string&s, int start, int end){
        while(start<end){
            if(s[start++]!=s[end--]){
                return false;
            }
        }
        return true;
    }
};