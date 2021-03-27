/*
 * @Description:
 *
 * 以 O(1) 的空间复杂度，判断链表是否为回文
 *
 * @输入示例：
 *
 * 1->2->3->2->1
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * 输入是一个链表,输出是一个布尔值,表示链表是否回文。
 *
 * @限制条件：
 *
 * 空间复杂度为 O(1)
 *
 * @题目思路：
 *
 * 先使用快慢指针找到链表终点，再把链表切成两半，然后把后半段翻转，最后比较两段是否相同
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

// 辅函数--翻转链表
ListNode* reverseList(ListNode* head) {
  ListNode* next = nullptr;
  ListNode* prev = nullptr;
  while (head) {
    next = head->next;
    head->next = prev;
    prev = head;
    head = next;
  }
  return prev;
}

class Solution {
 public:
  bool isPalindrome(ListNode* head) {
    // 考虑特殊情况
    if (!head || !head->next) {
      return true;
    }
    ListNode* slow = head;
    ListNode* fast = head;
    // 注意使用 fast 来做判断条件
    while (fast->next && fast->next->next) {
      slow = slow->next;
      fast = fast->next->next;
    }
    slow->next = reverseList(slow->next);
    slow = slow->next;
    while (slow) {
      if (head->val != slow->val) {
        return false;
      }
      head = head->next;
      slow = slow->next;
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }