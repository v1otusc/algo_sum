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
  // 找到第 n - k 个节点
  ListNode* getKthFromEnd(ListNode* head, int k) {
    ListNode* slow = head;
    ListNode* fast = head;
    if (!head || k == 0) return nullptr;
    for (int i = 0; i < k; ++i) {
      fast = fast->next;
    }
    while(fast) {
      slow = slow->next;
      fast = fast->next;
    }
    return slow;
  }
};

int main(int argc, char const* argv[]) { return 0; }