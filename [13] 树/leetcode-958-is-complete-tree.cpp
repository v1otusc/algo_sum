/*
 * @Description:
 *
 * 判断是否为完全二叉树
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
 * BFS
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
 public:
  bool isCompleteTree(TreeNode *root) {
    if (!root) {
      return true;
    }

    // 判断是否到达 最后一满层
    bool FIN = false;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      TreeNode *node = q.front();
      q.pop();

      if (node->left) {
        if (FIN) return false;
        q.push(node->left);
      } else {
        FIN = true;
      }

      if (node->right) {
        if (FIN) return false;
        q.push(node->right);
      } else {
        FIN = true;
      }
    }
    return true;
  }
};

int main(int argc, char const *argv[]) { return 0; }
