/*
 * @Description:
 *
 * 相加两个逆序(个位是第一个链表节点，以此类推)的链表
 *
 * @题目思路：
 *
 * 注意返回结果的构造方式
 * ListNode* res = new ListNode(-1);
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-17 20:07:42
 * @FilePath: /[12] 链表/leetcode-2-add-two-numbers.cpp
 */

#include "bits/stdc++.h"

struct ListNode {
  int val;
  ListNode* next;
  ListNode() : val(0), next(nullptr) {}
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

using namespace std;

class Solution {
 public:
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    // 加一个判断条件，能省好多时间
    if (!l1 || !l2) {
      return l1 ? l1 : l2;
    }
    ListNode* res = new ListNode(-1);
    ListNode* p = res;
    int carry = 0;
    int val = 0;
    while (l1 || l2 || carry > 0) {
      val = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
      carry = (val >= 10) ? 1 : 0;
      val = (carry == 1) ? (val - 10) : val;
      p->next = new ListNode(val);
      l1 = (!l1) ? l1 : l1->next;
      l2 = (!l2) ? l2 : l2->next;
      p = p->next;
    }
    return res->next;
  }
};

int main(int argc, char const* argv[]) { return 0; }
