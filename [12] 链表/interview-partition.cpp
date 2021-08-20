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
  ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
 public:
  ListNode* partition(ListNode* head, int x) {
    ListNode* small = new ListNode(0);
    ListNode* small_head = small;
    ListNode* large = new ListNode(0);
    ListNode* large_head = large;

    while (head) {
      if (head->val >= x) {
        large->next = head;
        large = large->next;
      } else {
        small->next = head;
        small = small->next;
      }
      head = head->next;
    }
    large->next = nullptr;
    small->next = large_head->next;
    // large_head->next = nullptr;
    return small_head->next;
  }
};

int main(int argc, char const* argv[]) { return 0; }