## 链表

(单)链表是由节点和指针构成的数据结构,每个节点存有一个值,和一个指向下一个节点的指针,因此很多链表问题可以用递归来处理。不同于数组,链表并不能直接获取任意节点的值,必须要通过指针找到该节点后才能获取其值。同理,在未遍历到链表结尾时,我们也无法知道链表的长度,除非依赖其他数据结构储存长度。LeetCode 默认的链表表示方法如下。

```c++
struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode *next) : val(x), next(next) {}
};
```

由于在进行链表操作时,尤其是删除节点时,经常会因为对当前节点进行操作而导致内存或指针出现问题。有两个小技巧可以解决这个问题:一是尽量处理当前节点的下一个节点而非当前节点本身,二是建立一个虚拟节点 (dummy node),使其指向当前链表的头节点,这样即使原链表所有节点全被删除,也会有一个 dummy 存在,返回 dummy->next 即可。

**注意：** 一般来说,算法题不需要删除内存。在刷 LeetCode 的时候,如果想要删除一个节点,可以直接进行指针操作而无需回收内存。实际做软件工程时,对于无用的内存,建议尽量显式回收,或利用智能指针。

**链表的 splice()**

list::splice实现list拼接的功能。将源list的内容部分或全部元素删除，拼插入到目的list。

函数有以下三种声明：

1. void splice ( iterator position, list<T,Allocator>& x );
2. void splice ( iterator position, list<T,Allocator>& x, iterator it );
3. void splice ( iterator position, list<T,Allocator>& x, iterator first, iterator last );

position 是要操作的list对象的迭代器

对于1，会在position把list &x所有的元素到**剪接**到要操作的list对象，而不删除要操的list对象中的元素。

对于2，只会把it的值剪接到要操作的list对象。

对于3，把first 到 last 剪接到要操作的list对象中。
