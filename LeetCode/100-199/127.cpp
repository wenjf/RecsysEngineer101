/*
凡是访问过的词，都可以删掉了。
这是这一题的关键点；再配合BFS就了可以简单解决这个问题了。
为什么呢？

*/

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> hash_set;
        for(auto w: wordList){
            hash_set.insert(w);
        }
        if(hash_set.find(endWord)==hash_set.end())
            return 0;
        int res = 2;
        queue<string> q;
        q.push(beginWord);
        while(q.size()){
            int q_size = q.size();
            for(int i = 0; i < q_size; ++i){
                string w1 = q.front();
                q.pop();
                vector<string> to_remove;
                for(auto new_word:hash_set){
                    if(GetWordDiff(w1, new_word) == 1){
                        if(new_word == endWord)
                            return res;
                        q.push(new_word);
                        to_remove.push_back(new_word);
                    }
                }
                for(auto w: to_remove){
                    hash_set.erase(w);
                }
            }
            res += 1;
        }
        return 0;
        
    }
    
    int GetWordDiff(string w1, string w2){
        int res = 0;
        for(int i = 0; i< w1.size(); ++i){
            if(w1[i] != w2[i])
                ++res;
        }
        return res;
    }
};