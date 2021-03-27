/*
 * @Description:
 *
 * 给定两个增序的链表，试将其合并成一个增序的链表
 *
 * @输入示例：
 *
 * 1->2->4
 * 1->3->4
 *
 * @输出实例：
 *
 * 1->1->2->3->4->4
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

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

// 递归的写法
/*class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // 考虑特殊情况
    if (!l1) {
      return l2;
    }
    if (!l2) {
      return l1;
    }

    if (l1->val > l2->val) {
      l2->next = mergeTwoLists(l1, l2->next);
      return l2;
    } else {
      l1->next = mergeTwoLists(l2, l1->next);
      return l1;
    }
  }
};*/

// 非递归的写法
class Solution {
 public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    // 将某个节点中的 val初始化为 0，方便 return 而已
    ListNode* dummy = new ListNode(0);
    ListNode* node = dummy;
    while (l1 && l2) {
      if (l1->val >= l2->val) {
        node->next = l2;
        l2 = l2->next;
      } else {
        node->next = l1;
        l1 = l1->next;
      }
      node = node->next;
    }
    node->next = l1 ? l1 : l2;
    return dummy->next;
  }
};

int main(int argc, char const* argv[]) { return 0; }