## 数据结构

<!-- TOC -->

- [数据结构](#数据结构)
  - [C++ STL](#c-stl)
    - [1. Sequence Containers: 维持顺序的容器](#1-sequence-containers-维持顺序的容器)
    - [2. Container Adaptors: 基于其他容器实现的数据结构](#2-container-adaptors-基于其他容器实现的数据结构)
    - [3. Associative Containers: 实现了拍好序的数据结构](#3-associative-containers-实现了拍好序的数据结构)
    - [4. Unordered Associative Containers: 对每个 Associative Containers 实现了哈希版本](#4-unordered-associative-containers-对每个-associative-containers-实现了哈希版本)

<!-- /TOC -->

### C++ STL

#### 1. Sequence Containers: 维持顺序的容器

(a) vector: 动态数组，是我们最常使用的数据结构之一,用于 **O(1)** 的随机读取。因为大部分算法的时间复杂度都会大于 O(n),因此我们经常新建 vector 来存储各种数据或中间变量。因为在尾部增删的复杂度是 O(1),我们也可以把它当作 stack 来用。

(b) list: 双向链表，也可以当作 stack 和 queue 来使用。由于 LeetCode 的题目多用 Node 来表示链表，且链表不支持快速随机读取,因此我们很少用到这个数据结构。一个例外是经典的 LRU 问题,我们需要利用链表的特性来解决,我们在后文会遇到这个问题。

(c) deque: 双端队列,这是一个非常强大的数据结构,既支持 O(1) 随机读取,又支持 O(1) 时间的头部增删和尾部增删,不过有一定的额外开销。

(d) array: 固定大小的数组，一般在刷题时我们不使用。

(f) forward_list: 单向链表，一般在刷题时我们不使用。

#### 2. Container Adaptors: 基于其他容器实现的数据结构

(a) stack: 后入先出(LIFO)的数据结构，默认基于 deque 实现。stack 常用于深度优先搜索、一些字符串匹配问题以及单调栈问题

(b) queue: 先入先出(FIFO)的数据结构，默认基于 deque 实现。queue 常用于广度优先搜索。

(c) priority_queue: 最大值先出的数据结构，默认基于 vector 实现堆结构，可以在 O(nlogn) 的时间内排序数组，,O(log n) 的时间插入任意值,O(1) 的时间获得最大值,O(log n) 的时间删除最大值。priority_queue 常用于维护数据结构并快速获取最大或最小值。



#### 3. Associative Containers: 实现了拍好序的数据结构



#### 4. Unordered Associative Containers: 对每个 Associative Containers 实现了哈希版本


