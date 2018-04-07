
/*
You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.

Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.

You are given an API bool isBadVersion(version) which will return whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.
*/

/*
binary search
考虑循环不变量，begin永远不是badVersion，所以缩小到两个以后，直接返回high.
*/

// Forward declaration of isBadVersion API.
bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int begin = 1;
        int end = n;
        int mid = (end - begin) / 2+ begin;
        if(isBadVersion(1)) return 1;
        while(end - begin > 1){
            if(isBadVersion(mid)){
                end = mid;
            }
            else{
                begin = mid;
            }
            mid = (end - begin) / 2+ begin;
        }
        return end;
        
    }
};