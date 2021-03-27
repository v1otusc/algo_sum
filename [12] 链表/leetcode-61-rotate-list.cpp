/*
 * @Description:
 *
 * 给你一个链表的头节点 head，旋转链表，将链表每个节点向右移动 k 个位置
 *
 * @输入示例：
 *
 * [1, 2, 3, 4, 5]
 * k = 2
 *
 * @输出实例：
 *
 * [4, 5, 1, 2, 3]
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 记给定链表的长度为 n，注意到当向右移动的次数 k≥n 时，我们仅需要向右移动
 k mod n 次即可。因为每 n
 次移动都会让链表变为原状。这样我们可以知道，新链表的最后一个节点为原链表的第
 (n−1)−(k mod n) 个节点（从 0 开始计数）。

 这样，我们可以先将给定的链表连接成环，然后将指定位置断开。

 具体代码中，我们首先计算出链表的长度
 n，并找到该链表的末尾节点，将其与头节点相连。这样就得到了闭合为环的链表。
 然后我们找到新链表的最后一个节点（即原链表的第
 (n−1)−(k mod n)个节点），将当前闭合为环的链表断开，即可得到我们所需要的结果。

 特别地，当链表长度不大于 1，或者 k 为 n
 的倍数时，新链表将与原链表相同，我们无需进行任何处理。
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
  static ListNode* rotateRight(ListNode* head, int k) {
    // 考虑特殊情况
    if (k == 0 || head == nullptr || head->next == nullptr) {
      return head;
    }
    // 首先计算出链表的长度
    int n = 1;
    ListNode* iter = head;
    while (iter->next != nullptr) {
      iter = iter->next;
      n++;
    }
    // 找到最后一个节点
    int add = n - k % n;
    if (add == n) {
      return head;
    }
    // 把链表闭合成环
    iter->next = head;
    while (add--) {
      iter = iter->next;
    }
    ListNode* ret = iter->next;
    iter->next = nullptr;
    return ret;
  }
};

int main(int argc, char const* argv[]) { return 0; }
