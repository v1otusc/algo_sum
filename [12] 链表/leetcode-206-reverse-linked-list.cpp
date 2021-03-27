/*
 * @Description:
 *
 * 翻转一个链表
 *
 * @输入示例：
 *
 * 1->2->3->4->5->nullptr
 *
 * @输出实例：
 *
 * 5->4->3->2->1->nullptr
 *
 * @输入输出说明：
 *
 * 输入一个链表，输出该链表翻转后的结果
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
};

// 递归的写法
class Solution {
 public:
  static ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
    if (!head) {
      return prev;
    }
    ListNode* next = head->next;
    head->next = prev;
    return reverseList(next, head);
  }
};

// 非递归的写法
/*class Solution {
 public:
  static ListNode* reverseList(ListNode* head, ListNode* prev = nullptr) {
    ListNode* prev = nullptr;
    ListNode* next = nullptr;
    while (head) {
      next = head->next;
      head->next = prev;
      prev = head;
      head = next;
    }
    return prev;
  }
};*/

int main(int argc, char const* argv[]) { return 0; }