/*
 * @Description:
 *
 * 给定两个链表,判断它们是否相交于一点,并求这个相交节点。
 *
 * @输入示例：
 *
 * NULL
 *
 * @输出实例：
 *
 * NULL
 *
 * @输入输出说明：
 *
 * 输入是两条链表,输出是一个节点。如无相交节点,则返回一个空节点。n
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 假设链表 A 的头节点到相交点的距离是 a,链表 B 的头节点到相交点的距离是
 b,相交点到链表终点的距离为 c。我们使用两个指针，分别指向两个链表的头节点
 并以相同速度前进，若到达链表结尾,则移动到另一条链表的头节点继续前进。按照这种前进方法,两个指针会在
 a+b+c 次前进后同时到达相交节点
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
    ListNode* l1 = headA;
    ListNode* l2 = headB;
    while (l1 != l2) {
      l1 = (l1) ? l1->next : headB;
      l2 = (l2) ? l2->next : headA;
    }
    return l1;
  }
};

int main(int argc, char const* argv[]) { return 0; }
