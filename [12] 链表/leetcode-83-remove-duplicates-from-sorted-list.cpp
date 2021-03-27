/*
 * @Description:
 *
 * 存在一个按升序排列的链表，给你这个链表的头节点 head
 * 请你删除所有重复的元素，使每个元素 只出现一次 。
 *
 * @输入示例：
 *
 * head = [1, 1, 2]
 *
 * @输出实例：
 *
 * [1, 2]
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
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

// Definition for singly-linked list.
struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  static ListNode* deleteDuplicates(ListNode* head) {
    // 考虑特殊情况
    if (!head) {
      return head;
    }
    ListNode* cur = head;
    while (cur->next) {
      if (cur->val == cur->next->val) {
        cur->next = cur->next->next;
      } else {
        cur = cur->next;
      }
    }
    return head;
  }
};

int main(int argc, char const* argv[]) { return 0; }