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
  bool isValidBST(TreeNode *root) { return isValid(root, nullptr, nullptr); }
  bool isValid(TreeNode *root, TreeNode *min, TreeNode *max) {
    if (root == nullptr) return true;
    if (min != nullptr && root->val <= min->val) return false;
    if (max != nullptr && root->val >= max->val) return false;
    return isValid(root->left, min, root) && isValid(root->right, root, max);
  }
};

int main(int argc, char const *argv[]) { return 0; }
