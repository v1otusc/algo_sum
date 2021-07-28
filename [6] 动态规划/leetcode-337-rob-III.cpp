/*
 * @Description:
 *
 * 树形打家劫舍
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
  unordered_map<TreeNode *, int> memo;

 public:
  int rob(TreeNode *root) { return dp(root); }

  int dp(TreeNode *node) {
    if (!node) return 0;
    if (memo.count(node)) {
      return memo[node];
    }
    int do_it =
        node->val +
        ((!node->left) ? 0 : dp(node->left->left) + dp(node->left->right)) +
        ((!node->right) ? 0 : dp(node->right->left) + dp(node->right->right));
    int not_do_it = dp(node->left) + dp(node->right);
    int res = max(do_it, not_do_it);
    memo[node] = res;
    return res;
  }
};

int main(int argc, char const *argv[]) { return 0; }
