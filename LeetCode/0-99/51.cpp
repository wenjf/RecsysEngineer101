//N queens which is a very classical problem

class Solution {
public:
    //nr：目前处理第几行
    void backing(int nr, vector<vector<string>>& res, vector<string>& temp){
        //如果已经装满了，而且因为是合法解才会进入到这里，所以认为这是合法解之一
        if(nr >= temp.size()){
            res.push_back(temp);
            return;
        }
        //遍历当前行的所有位置
        for(int j = 0; j<temp.size(); ++j){
            temp[nr][j] = 'Q';//这里也隐藏了每一行只放一个
            if(is_valid(temp, nr, j)){
                //进入递归调用进入下一轮
                backing(nr+1, res, temp);
            }
            temp[nr][j] = '.';//回溯
        }  
    }
    
    //由于第12行的隐含条件，这里只需要检查第J列，左斜，右斜
    bool is_valid(vector<string>& temp, int row, int col){
        //检查列
        for(int i = row - 1; i>= 0 ; --i){
            if(temp[i][col] - 'Q' == 0)
                return false;
        }
        //检查从当前到右上 i for row，j for col
        for(int i=row-1, j = col + 1; i>= 0 && j<temp.size(); --i, ++j )
            if(temp[i][j] - 'Q' == 0)
                return false;
        //检查当前到左上
        for(int i=row-1, j = col - 1; i>= 0 && j>=0; --i, --j )
            if(temp[i][j] - 'Q' == 0)
                return false;
        //全部合法
        return true;
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        vector<string> temp(n, string(n, '.'));
        backing(0, res, temp);
        return res;
    }
};