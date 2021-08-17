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
 * 使用双指针的思路
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
  void reorderList(ListNode* head) {
    if (head == nullptr) return;
    vector<ListNode*> node_vec;
    int n = 0;
    while (head) {
      node_vec.push_back(head);
      head = head->next;
      n++;
    }
    int left = 0, right = n - 1;
    while (left < right) {
      node_vec[left]->next = node_vec[right];
      left++;
      if (left == right) break;
      node_vec[right]->next = node_vec[left];
      right--;
    }
    node_vec[left]->next = nullptr;
    return;
  }
};

int main(int argc, char const* argv[]) { return 0; }
