/*
如何使用递归呢？
如何高效的使用递归呢？
这一题就是一个比较典型的题目；
要考虑上下左右是否越界；怎么高效的利用递归来做这个事情呢、
*/

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int x=0;x<m;x++)
            for(int y=0;y<n;y++){
                if(FindElement(board,word.c_str(),x,y))
                    return true;
            }
        return false;
    }
    
    bool FindElement(vector<vector<char>>& board,const char* w, int x, int y){
        if(x<0||y<0||x>=board.size()||y>board[0].size())
            return false;
        if(w[0] == '\0')
            return true;
        if(board[x][y] != w[0])
            return false;
        board[x][y] = '\0';
        if(FindElement(board, w+1, x-1, y)||FindElement(board, w+1, x, y-1)||FindElement(board, w+1, x+1, y)||FindElement(board, w+1, x, y+1))
            return true;
        board[x][y] = w[0];
        return false;
    }
};