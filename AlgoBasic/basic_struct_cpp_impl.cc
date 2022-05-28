#include<vector>

using namespace std;
// heap
// -- method 1 -- 
vector<int> maxHeap;
make_heap(maxHeap.begin(), maxHeap.end()); // 建堆，默认最大堆，cmp 是 < ， 
pop_heap(maxHeap); // 把最大的元素调整到vector的末尾
maxHeap.pop_back(); // 把最大元素弹出去
// -- enf of method 1 -- 

// -- method 2 -- 
#include<queue>
priority_queue<int> pq; // 默认也是最大堆
/* 模板的拓展方法
    std::priority_queue<int, std::vector<int>, std::greater<int>>
        q2(data.begin(), data.end());
*/
// -- enf of method 2 -- 


// hash map

// hash set


// count element freq use stl


// partition，也就是快排的partition算法，常用语求解top K问题 
vector<int> nums;
int k;
nth_element(nums.begin(), nums.begin() + k -1, nums.end()); 

// binary search
int target;
auto iter = lower_bound(nums.begin(), nums.end(), target); // 找到第一个大于target的元素对应的iterator
auto iter upper_bound(nums.begin(), nums.end(), target); // 找到第一个小于target元素对应的iterator
// 要求nums是有序的
// iter的类型为iterator