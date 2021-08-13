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
  vector<int> rightSideView(TreeNode *root) {
    vector<int> ans;
    if (!root) return ans;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        TreeNode *node = q.front();
        q.pop();
        if (i == sz - 1) {
          ans.push_back(node->val);
        }
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
      }
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) { return 0; }
