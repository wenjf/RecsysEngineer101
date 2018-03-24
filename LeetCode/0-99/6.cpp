/*
The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

P   A   H   N
A P L S I I G
Y   I   R
And then read line by line: "PAHNAPLSIIGYIR"
Write the code that will take a string and make this conversion given a number of rows:

string convert(string text, int nRows);
convert("PAYPALISHIRING", 3) should return "PAHNAPLSIIGYIR".
*/
//-------------------------------------------------------------------------------------------------------------------------------------------------------------------

/*
最简单的思路，为转换后的每一层存一个string；遍历输入，判断每个字符属于哪一层，将其append在对应string的最后即可。
最后把每一层的string拼接起来返回。
*/


class Solution {
public:
    string convert(string s, int numRows) {
        string res = s;
        vector<string> temp(numRows);
        if(numRows == 1) return res;
        for(int i = 0; i < s.size(); i ++){
            int n_zig = (i+1) %(2*numRows - 2);
            if (n_zig == 0){
                temp[1].push_back(s[i]);
            }else if(n_zig / numRows == 1){
                int num_reverse = n_zig % numRows;
                temp[numRows - num_reverse - 1].push_back(s[i]);
            }else{
                temp[n_zig - 1].push_back(s[i]);
            }
        }
        res = "";
        for(auto iter = temp.begin();iter!=temp.end();++iter){
            if(iter->size()>0)
                res.append(*iter);
        }
        return res;
    }
};