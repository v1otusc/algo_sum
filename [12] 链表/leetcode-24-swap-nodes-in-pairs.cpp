/*
 * @Description:
 *
 给定一个链表，两两交换其中相邻的节点，并返回交换后的链表。
 你不能只是单纯的改变节点内部的值，而是需要实际的进行节点交换。
 *
 * @输入示例：
 *
 * 1->2->3->4
 *
 * @输出实例：
 *
 * 2->1->4->3
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
 * 利用指针进行交换操作，一定要细心
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

class Solution {
 public:
  ListNode* swapPairs(ListNode* head) {
    ListNode* p = head;
    ListNode* s;
    if (p && p->next) {
      s = p->next;
      p->next = s->next;
      s->next = p;
      head = s;
      while (p->next && p->next->next) {
        s = p->next->next;
        p->next->next = s->next;
        s->next = p->next;
        p->next = s;
        p = s->next;
      }
    }
    return head;
  }
};

int main(int argc, char const* argv[]) { return 0; }
