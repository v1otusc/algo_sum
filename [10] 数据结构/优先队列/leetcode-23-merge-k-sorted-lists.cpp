/*
 * @Description:
 *
 * 给定 k 个增序的链表，试将他们合并成一条增序链表
 *
 * @输入示例：
 *
 * [1->4->5,
 *  1->3->4,
 *  2->6]
 *
 * @输出实例：
 *
 *  1->1->2->3->4->4->5->6
 *
 * @输入输出说明：
 *
 * 输入是一个一维数组,每个位置存储链表的头节点;输出是结果链表的头节点
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 把所有的链表存储在一个优先队列中，每次提取所有链表头部节点值最小的那个节点
 * 直到所有的链表被提取完为止。注意因为 cmp
 * 函数默认是对最大堆进行比较并维持递增关系
 * 如果我们想要获取最小的节点值,则我们需要实现一个最小堆,因此比较函数应该维持递减
 * 关系，所以 operator() 中返回时用大于号；
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
  // 采用仿函数，实现小根堆，使用大于号 实现大根堆，使用小于号
  struct cmp {
    bool operator()(ListNode* l1, ListNode* l2) { return l1->val > l2->val; }
  };

 public:
  ListNode* mergeKLists(vector<ListNode*>& lists) {
    if (lists.empty()) {
      return nullptr;
    }
    priority_queue<ListNode*, vector<ListNode*>, cmp> q;
    for (ListNode* list : lists) {
      if (list) {
        q.push((list));
      }
    }
    ListNode* dummy = new ListNode(0);
    ListNode* cur = dummy;
    while (!q.empty()) {
      cur->next = q.top();
      q.pop();
      cur = cur->next;
      if (cur->next) {
        q.push(cur->next);
      }
    }
    return dummy->next;
  }
};

int main(int argc, char const* argv[]) { return 0; }
