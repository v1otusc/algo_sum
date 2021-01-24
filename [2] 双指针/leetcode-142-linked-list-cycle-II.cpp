/*
 * @Description:
 *
 * 给定一个链表，返回链表开始入环的第一个节点。如果链表无环，则返回 null。
 * 为了表示给定链表中的环，我们使用整数 pos
 * 来表示链表尾连接到链表中的位置（索引从 0 开始）。 如果 pos 是
 * -1，则在该链表中没有环。注意，pos
 * 仅仅是用于标识环的情况，并不会作为参数传递到函数中。
 * 注意，不允许修改给定的链表
 *
 * @输入示例：
 *
 * 一个 val 为整数的链表，参考给定的 struct ListNode
 *
 * @输出实例：
 *
 * pos: 开始入环的第一个节点
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 *  链表中节点的数目范围在范围 [0, 104] 内
 *  -105 <= Node.val <= 105
 *  pos 的值为 -1 或者链表中的一个有效索引
 *
 * @题目思路：
 *
 * 对于链表找环路的问题，有一种通用的解法，快慢指针(Floyd
 * 判圈法)，给定两个指针。分别命名为 slow 和 fast
 * 起始位置在链表的开头，每次 fast 前进两步，slow 前进一步，如果
 * fast 可以走到尽头，说明没有环路，
 * 如果 fast 可以无限走下去，说明一定有环路，
 * 且一定存在一个时刻 slow 和 fast 相遇，当第一次相遇时，将 fast 移到链表的开头
 * 并且让 slow 和 fast 每次都前进一步，当 slow 和 fast
 * 第二次相遇时，相遇的节点就是环路的开始点（入环的第一个节点）
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

// 如果没有特殊说明，采用如下的数据结构表示链表
struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr){};
};

class Solution {
 public:
  static ListNode* detectCycle(ListNode* head) {
    ListNode* fast;
    ListNode* slow;
    // 首先一定要考虑特殊情况，如果只有一个或者两个 ListNode，必不可能有环路
    if (!fast->next || !fast->next->next) {
      return nullptr;
    }

  }
};

int main(int argc, char const* argv[]) {
  // 首先构造一个链表
  
  return 0;
}