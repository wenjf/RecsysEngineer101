/*
Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/

/*
* 回溯
*/

void generator(int left, int right, vector<string>& res, string& one_res){
    if(left == 0&& right ==0){
        res.push_back(one_res);
        return;
    }
    if(left>0){
        generator(left-1, right+1, res, one_res.append("(") );           
        one_res.pop_back();
    }
    if(right>0){
        generator(left, right -1, res, one_res.append(")"));
        one_res.pop_back();
    }
}

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string s = ""; 
        generator(n, 0, res, s);
        return res;
    }
};