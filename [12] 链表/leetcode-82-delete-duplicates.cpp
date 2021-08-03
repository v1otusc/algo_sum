/*
 * @Description:
 *
 * 升序链表，保留链表中不重复的节点
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
  ListNode(int x, ListNode* next) : val(x), next(nullptr) {}
};

class Solution {
 public:
  ListNode* deleteDuplicates(ListNode* head) {
    if (!head) return head;

    // 由于链表的头节点可能被删除，所以需要一个哑节点
    ListNode* dummy = new ListNode(-1, head);
    ListNode* cur = dummy;
    while (cur->next && cur->next->next) {
      if (cur->next->val == cur->next->next->val) {
        int x = cur->next->val;
        // x 提出来的作用就是用来做判断的
        while (cur->next && cur->next->val == x) {
          cur->next = cur->next->next;
        }
      } else {
        cur = cur->next;
      }
    }

    return dummy->next;
  }
};

int main(int argc, char const* argv[]) { return 0; }
