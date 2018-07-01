class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0) return "";
        string res;
        int i = 0;
        char c;
        while(1){
            int is_first = 0;
            for(auto iter = strs.begin(); iter!=strs.end(); iter++){
                if(i>=iter->size())
                    return res;
                if(is_first==0){
                    c = (*iter)[i];
                    is_first = 1;
                }
                else if( c  - (*iter)[i] !=0){
                    return res;
                }

            }
            res.push_back(c);
            i++;
        }
        return res;

        
    }
};