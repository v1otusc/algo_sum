/*
 * @Description:
 *
 *
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
 * 折半查找
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
  bool isPalindrome(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return true;
    ListNode* slow = head;
    ListNode* fast = head;

    while (fast && fast->next) {
      slow = slow->next;
      fast = fast->next->next;
    }

    if (fast != nullptr) slow = slow->next;
    ListNode* r_head = slow;

    ListNode* reverse_r_head = reverse_list(r_head);
    while (reverse_r_head && head) {
      if (reverse_r_head->val == head->val) {
        reverse_r_head = reverse_r_head->next;
        head = head->next;
      } else {
        return false;
      }
    }
    return true;
  }

  ListNode* reverse_list(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    ListNode* cur = head;
    ListNode* pre = nullptr;
    // 嫖娼难方法
    while (cur) {
      ListNode* nex = cur->next;
      cur->next = pre;
      pre = cur;
      cur = nex;
    }
    return pre;
  }
};

int main(int argc, char const* argv[]) { return 0; }