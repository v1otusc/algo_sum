/*
 * @Description:
 *
 * 给你一个链表，每 k 个节点一组进行翻转，请你返回翻转后的链表。
 *
 * k 是一个正整数，它的值小于等于链表的长度
 *
 * 如果节点总数不是 k 的整数倍，那么请将最后剩余的节点保持原有顺序
 *
 * @输入示例：
 *
 * head = [1, 2, 3, 4, 5], k = 2
 *
 * @输出实例：
 *
 * [2, 1, 4, 3, 5]
 *
 * @输入输出说明：
 *
 * 最后剩余的节点保持原有的顺序
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
  // 翻转一个子链表，并且返回新的头与尾
  pair<ListNode*, ListNode*> myreverse(ListNode* head, ListNode* tail) {
    ListNode* prev = tail->next;
    ListNode* p = head;
    while (prev != tail) {
      // 不能写作 while(p != tail->next)
      // 否则会有 ListNode* nex = nullptr->next;
      ListNode* nex = p->next;
      p->next = prev;
      prev = p;
      p = nex;
    }
    return make_pair(tail, head);
  }

  ListNode* reverseKGroup(ListNode* head, int k) {
    ListNode* h = new ListNode(0);
    h->next = head;
    ListNode* pre = h;

    while (head) {
      ListNode* tail = pre;

      // 查看剩余部分的长度是否大于 k
      for (int i = 0; i < k; ++i) {
        tail = tail->next;
        if (!tail) {
          return h->next;
        }
      }

      ListNode* nex = tail->next;

      pair<ListNode*, ListNode*> result = myreverse(head, tail);
      head = result.first;
      tail = result.second;
      // 把子链表放回原链表
      pre->next = head;
      tail->next = nex;
      pre = tail;
      head = tail->next;
    }

    return h->next;
  }
};

int main(int argc, char const* argv[]) { return 0; }
