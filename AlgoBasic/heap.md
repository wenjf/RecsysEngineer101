# 最大堆/有限队列

一颗完全二叉树，特点是根节点一定比子节点大。
子树也完全符合这个性质。

基本操作：
insert：log(N) 需要做上滤，percolate up

delete: log(N) 需要下滤，percolate down

build：依次下滤，O(N)复杂度

## 经典题目

top K frequence
leetcode 347
leetcode 692




### REF:
[markdown写作帮助](https://zhuanlan.zhihu.com/p/56699805)