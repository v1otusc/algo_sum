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
 * 深度优先搜索
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
  int dfs(TreeNode *root, int prev) {
    if (!root) return 0;
    int sum = prev * 10 + root->val;
    if (root->left == nullptr && root->right == nullptr)
      return sum;
    else {
      return dfs(root->left, sum) + dfs(root->right, sum);
    }
  }

  int sumNumbers(TreeNode *root) { return dfs(root, 0); }
};

int main(int argc, char const *argv[]) { return 0; }
