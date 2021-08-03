/*
 * @Description:
 *
 * 反转一部分链表
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
 private:
  // 表示第 n + 1 个节点
  ListNode* successor = nullptr;

 public:
 // 翻转前 n 个节点
  ListNode* reverseN(ListNode* head, int n) {
    if (n == 1) {
      successor = head->next;
      return head;
    }
    ListNode* last = reverseN(head->next, n - 1);
    head->next->next = head;
    head->next = successor;
    return last;
  }

 public:
  ListNode* reverseBetween(ListNode* head, int left, int right) {
    // 记录第 n + 1 个节点
    if (left == 1) {
      return reverseN(head, right);
    }
    head->next = reverseBetween(head->next, left - 1, right - 1);
    return head;
  }
};

int main(int argc, char const* argv[]) { return 0; }
