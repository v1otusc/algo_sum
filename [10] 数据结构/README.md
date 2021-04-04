## 数据结构

<!-- TOC -->

- [数据结构](#数据结构)
  - [C++ STL](#c-stl)
    - [1. Sequence Containers: 维持顺序的容器](#1-sequence-containers-维持顺序的容器)
    - [2. Container Adaptors: 基于其他容器实现的数据结构](#2-container-adaptors-基于其他容器实现的数据结构)
    - [3. Associative Containers: 实现了排好序的数据结构](#3-associative-containers-实现了排好序的数据结构)
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

(c) priority_queue: 最大值先出的数据结构，默认基于 vector 实现堆结构，可以在 O(nlogn) 的时间内排序数组，,O(logn) 的时间插入任意值,O(1) 的时间获得最大值,O(logn) 的时间删除最大值。priority_queue 常用于维护数据结构并快速获取最大或最小值。

优先队列常常用堆(heap)来实现。堆是一个完全二叉树,其每个节点的值总是大于等于子节点的值。实际实现堆时,我们通常用一个数组而不是用指针建立一个树。这是因为堆是完全二叉树,所以用数组表示时,位置 i 的节点的父节点位置一定为 i/2,而它的两个子节点的位置又一定分别为 2i 和 2i+1。

以下是堆的实现方法，其中最核心的两个操作是上浮和下沉：如果一个节点比父节点大，那么需要交换这两个节点；交换后还可能比它新的父节点大,因此需要不断地进行比较和交换操作，我们称之为上浮；类似地，如果一个节点比父节点小，也需要不断地向下进行比较交换操作，我们称之为下沉。如果一个节点有两个子节点，总是交换最大的子节点。

```c++
// 对于一个大小为 N 的堆，heap[0] = 0
// heap[1] 到 heap[N] 为堆中的元素，所以 heap.size() = N + 1
vector<int> heap;

// 获得最大值
int top() {
  return heap[1];
}

// 插入任意值：把新的数字放在最后一位，然后上浮
void push(int k) {
  heap.push_back(k);
  swim(heap.size()-1);
}

// 删除最大值：把最后一个数字挪到开头，然后下沉
void pop() {
  heap[1] = heap.back();
  heap.pop_back();
  sink(1);
}

// 上浮
void swim(int pos) {
  while (pos > 1 && heap[pos/2] > heap[pos]) {
    swap(heap[pos/2], heap[pos]);
    pos /= 2;
  }
}

// 下沉
void sink(int pos) {
  while(2*pos <= N) {
    int i = 2*pos;
    // 找出两个子节点中的最大值
    if (i < N && heap[i] < heap[i+1]) ++i;
    if (heap[pos] >= heap[i]) break;
    swap(heap[pos], heap[i]);
    pos = i;
  }
}
```

通过将算法中的大于号和小于号互换,我们也可以得到一个快速获得最小值的优先队列。

另外，如果我们需要在维持大小关系的同时,还需要支持查找任意值、删除任意值、维护所有数字的大小关系等操作,可以考虑使用 set 或 map 来代替优先队列。

#### 3. Associative Containers: 实现了排好序的数据结构

(a) set：有序集合，元素不可重复，底层实现默认为红黑树，即一种特殊的二叉查找树(BST)。可以在 O(nlogn) 的时间排序数组, O(logn) 的时间插入、删除、查找任意值，O(logn) 的时间内获得最大最小值。这里注意，set 和 priority_queue 都可以用于维护数据结构并快速获取最大最小值,但是它们的时间复杂度和功能略有区别,如priority_queue 默认不支持删除任意值,而 set 获得最大或最小值的时间复杂度略高,具体使用哪个根据需求而定；

(b) multiset: 支持重复元素的 set;

(c) map: 有序映射或有序表,在 set 的基础上加上映射关系,可以对每个元素 key 存一个值 value。

(d) multimap: 支持重复元素的 map;

#### 4. Unordered Associative Containers: 对每个 Associative Containers 实现了哈希版本

哈希表，又称散列表，使用 O(n) 空间复杂度存储数据,通过哈希函数映射位置,从而实现近似 O(1) 时间复杂度的插入、查找、删除等操作。但是如果需要大小关系的维持，且插入查找并不过于频繁，则使用有序的 set/map 来代替 unordered_set/unordered_map。

(a) unordered_set: 哈希集合，可以在 O(1) 的时间内插入、查找、删除元素，常用于快速得查询一个元素是否在这个容器内;

(b) unordered_multiset: 支持重复元素的 unordered_set。

(c) unordered_map: :哈希映射或哈希表,在 unordered_set 的基础上加上映射关系,可以对每一个元素 key 存一个值 value。在某些情况下,如果 key 的范围已知且较小,我们也每一个元素 key 存一个值 value。在某些情况下,如果 key 的范围已知且较小,我们也可以用 vector 代替 unordered_map,用位置表示 key,用每个位置的值表示 value。

(d) unordered_multimap:支持重复元素的 unordered_map。

一个简单的哈希表的实现如下：

```c++
template <typename T>
class HashTable {
  
}
```
