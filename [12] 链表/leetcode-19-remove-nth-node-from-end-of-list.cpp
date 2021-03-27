/*
 * @Description:
 *
 * 给你一个链表，删除链表的倒数第 n 个结点，并且返回链表的头结点。
 * 并且返回链表的头结点
 *
 * @输入示例：
 *
 * 1->2->3->4->5
 * n = 2
 *
 * @输出实例：
 *
 * 1->2->3->5
 *
 * @输入输出说明：
 *
 *
 *
 * @限制条件：
 *
 * 使用一次扫描实现
 *
 * @题目思路：
 *
 * 用两个指针来帮助解题，pre 和 cur 指针。首先 cur 指针先向前走 n 步，如果此时
 * cur 指向空，说明 n 为链表的长度，则需要移除的为首元素，那么此时返回
 * head->next 即可，如果 cur 存在，再继续往下走，此时 pre 指针也跟着走，直到 cur
 * 为最后一个元素时停止，此时 pre
 * 指向要移除元素的前一个元素，再修改指针跳过需要移除的元素即可，参见代码如下：
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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* removeNthFromEnd(ListNode* head, int n) {
    if (!head || !head->next) {
      return nullptr;
    }
    ListNode* pre = head;
    ListNode* cur = head;
    for (int i = 0; i < n; ++i) {
      cur = cur->next;
    }
    if (!cur) {
      return head->next;
    }
    while (cur->next) {
      cur = cur->next;
      pre = pre->next;
    }
    pre->next = pre->next->next;
    return head;
  }
};

int main(int argc, char const* argv[]) { return 0; }