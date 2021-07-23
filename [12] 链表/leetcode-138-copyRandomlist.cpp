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
 * 哈希表存 旧链表节点——新链表节点
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  Node* copyRandomList(Node* head) {
    // 旧链表节点——新链表节点
    unordered_map<Node*, Node*> map;
    Node* cur = head;
    while (cur != NULL) {
      map[cur] = new Node(cur->val);
      cur = cur->next;
    }
    cur = head;
    while (cur != NULL) {
      map[cur]->next = map[cur->next];
      map[cur]->random = map[cur->random];
      cur = cur->next;
    }
    return map[head];
  }
};

int main(int argc, char const* argv[]) { return 0; }