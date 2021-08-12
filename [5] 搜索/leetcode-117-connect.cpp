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

// Definition for a Node.
class Node {
 public:
  int val;
  Node* left;
  Node* right;
  Node* next;

  Node() : val(0), left(NULL), right(NULL), next(NULL) {}

  Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

  Node(int _val, Node* _left, Node* _right, Node* _next)
      : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
 public:
  Node* connect(Node* root) {
    if (root == nullptr) return nullptr;
    queue<Node*> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      Node* last = nullptr;
      for (int i = 0; i < sz; ++i) {
        Node* cur = q.front();
        q.pop();

        if (cur->left) q.push(cur->left);
        if (cur->right) q.push(cur->right);

        if (i != 0) {
          last->next = cur;
        }
        last = cur;
      }
    }
    return root;
  }
};
