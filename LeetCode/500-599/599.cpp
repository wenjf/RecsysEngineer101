class Solution {
public:
    vector<string> findRestaurant(vector<string>& list1, vector<string>& list2) {
        vector<string> the_restaurant;
        int min_index = 9999;
        unordered_map<string, int> m;
        unordered_map<string, int> m2;
        int index = 0;
        for(auto iter = list1.begin();iter !=list1.end();iter++)
            m.insert(pair<string,int>(*iter, index++));
        index = 0;
        for(auto iter = list2.begin();iter != list2.end();iter++){
            if(m.find(*iter)!=m.end())
                m2[*iter] = m[*iter] + index;
            index++; 
        }
        for(auto iter = m2.begin();iter!=m2.end();iter++){
            if(iter->second == min_index){
                the_restaurant.push_back(iter->first);
            }
            if(iter->second < min_index){
                min_index = iter->second;
                the_restaurant.clear();
                the_restaurant.push_back(iter->first);
            }
        }
        return the_restaurant;
    }
};