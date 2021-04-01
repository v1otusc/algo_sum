/*
 * @Description:
 *
 * 给定一个单向链表，要求设计一个算法，可以随机取得其中的一个数字
 *
 * @输入示例：
 *
 * 1->2->3->4->5
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 输入是一个单向链表，输出是其中一个数字，表示链表里其中一个节点的值
 * 在这个样例中，我们有均等的概率得到任意一个节点，比如 3
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 不同于数组,在未遍历完链表前,我们无法知道链表的总长度。
 * 使用蓄水池算法，详见 README.md 
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
  ListNode* head;

 public:
  Solution(ListNode* n) : head(n) {}
  int getRandom() {
    int ans = head->val;
    ListNode* node = head->next;
    int i = 2;
    while (node) {
      // 产生指定范围内的随机数
      if ((rand() % i) == 0) {
        ans = node->val;
      }
      ++i;
      node = node->next;
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
