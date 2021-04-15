## 数据结构-II

### 并查集

并查集(union-find, 或 disjoint set)可以动态地连通两个点,并且可以非常快速地判断两个点是否连通。假设存在 n 个节点,我们先将所有节点的父亲标为自己;每次要连接节点 i 和 j 时,我们可以将 i 的父亲标为 j;每次要查询两个节点是否相连时,我们可以查找 i 和 j 的祖先是否最终为同一个人。

![](../figs/union%20set.png)

### 复合数据结构

这一类题通常采用 unordered_map 或 map 辅助记录，从而加速寻址，再配上 vector 或 list 进行数据储存，从而加速连续选址或删除值。

LRU: 最少最近使用缓存(least recently used cache, LRU)

[最少最近使用缓存](https://leetcode-cn.com/problems/lru-cache/solution/lru-ce-lue-xiang-jie-he-shi-xian-by-labuladong/)