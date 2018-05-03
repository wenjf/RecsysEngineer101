//一个比较蠢的方法

/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int partition(vector<Interval>& input, int l, int r){
        int s = l-1; //from l to s, is the interval.start < key.start
        for(int i = l; i <= r; ++i){
            if(input[i].start< input[r].start||(input[i].start == input[r].start&&input[i].end< input[r].end)){
                ++s;
                Interval temp = input[s];
                input[s] = input[i];
                input[i] = temp;
            }
        }
        Interval temp = input[++s];
        input[s] = input[r];
        input[r] = temp;
        return s;
    }
    
    void interval_quick_sort(vector<Interval>& intervals, int l, int r){
        if(r<=l)
            return;
        int key = partition(intervals, l, r);
        std::cout << key << std::endl;
        if(key>0)
            interval_quick_sort(intervals, l, key-1);
        if(key < r)
            interval_quick_sort(intervals, key+1, r);
    }
    
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size() == 0)
             return  vector<Interval>();
        interval_quick_sort(intervals, 0, intervals.size()-1);
        vector<Interval> res;
        Interval temp;
        int temp_end = intervals[0].end;
        temp.start = intervals[0].start;
        for(int i = 0; i < intervals.size()-1; i++) {
            if(temp_end < intervals[i+1].start){
                temp.end =  temp_end;
                res.push_back(temp);
                temp.start = intervals[i+1].start;
                temp_end = intervals[i+1].end;
            }
            temp_end = max(temp_end, intervals[i+1].end);
        }
        temp_end = max(temp_end, intervals[intervals.size()-1].end);
        temp.end = temp_end;
        res.push_back(temp);
        return res;
    }
};