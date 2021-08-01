/*
 * @Description:
 *
 * 二叉树的最小深度
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
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  int minDepth(TreeNode* root) {
    if (!root) return 0;
    if (root->left == nullptr && root->right == nullptr) return 1;
    int depth = INT_MAX;
    if (root->left != nullptr) {
      depth = min(minDepth(root->left), depth);
    }
    if (root->right != nullptr) {
      depth = min(minDepth(root->right), depth);
    }
    return depth + 1;
  }
};

int main(int argc, char const* argv[]) { return 0; }
