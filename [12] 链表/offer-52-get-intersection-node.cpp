/*
 * @Description:
 *
 * 求两个链表的相交节点
 *
 * @输入示例：
 *
 *
 *
 * @输出实例：
 *
 *
 *
 * @输入输出说明：
 *
 *
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 链表 headA 和 headB 的长度分别是 m 和
 * n。假设链表 headA 的不相交部分有 a 个节点，链表
 * headB 的不相交部分有 b 个节点，两个链表相交的部分有 c
 * 个节点，则有 a+c=m，b+c=n。
 *
 * 指针 pA 会遍历完链表 headA，指针 pB 会遍历完链表
 * headB，两个指针不会同时到达链表的尾节点，然后指针 pA 移到链表 headB
 * 的头节点，指针 pB 移到链表 headA 的头节点，然后两个指针继续移动，在指针 pA
 * 移动了 a+c+b 次、指针 pB 移动了 b+c+a
 * 次之后，两个指针会同时到达两个链表的第一个公共节点，该节点也是两个指针第一次同时指向的节点，此时返回两个链表的第一个公共节点。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

struct ListNode {
  int val;
  ListNode *next;
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
    if (headA == nullptr || headB == nullptr) {
      return nullptr;
    }
    ListNode *p1 = headA;
    ListNode *p2 = headB;
    // 很优雅的解决方法
    // 两指针都是 nullter 也是相等
    while (p1 != p2) {
      p1 = (p1 == nullptr) ? headB : p1->next;
      p2 = (p2 == nullptr) ? headA : p2->next;
    }
    return p1;
  }
};

int main(int argc, char const *argv[]) { return 0; }
