void combinator(int begin, string& digits, vector<string>& kb, vector<string>& res, string& one_res){
    if(begin >= digits.size()){
        res.push_back(one_res);
        return;
    }
    int digit = digits[begin] - '0';
    string& candidate = kb[digit-2];
    for(int i = 0; i< candidate.size(); ++i ){
        one_res.push_back(candidate[i]);
        combinator(begin+1, digits, kb, res, one_res);
        one_res.pop_back();
    }
}


class Solution {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return vector<string>();
        vector<string> kb = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> res;
        string one_res;
        combinator(0, digits, kb, res, one_res);
        return res;
    }
};