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
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  ListNode* deleteDuplicatesUnsorted(ListNode* head) {
    if (head == nullptr || head->next == nullptr) return head;
    // val - fre
    unordered_map<int, int> ump;
    ListNode* cur = head;
    while (cur) {
      ump[cur->val]++;
      cur = cur->next;
    }

    // head 也有可能被剔除
    ListNode* dummy = new ListNode(-1);
    dummy->next = head;
    // 使用递归
    ListNode* curr = dummy;
    while (curr->next) {
      if (ump[curr->next->val] > 1) {
        curr->next = curr->next->next;
      } else {
        curr = curr->next;
      }
    }
    return dummy->next;
  }
};

int main(int argc, char const* argv[]) { return 0; }
