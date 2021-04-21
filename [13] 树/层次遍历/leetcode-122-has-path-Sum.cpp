/*
 * @Description:
 *
 * 给你二叉树的根节点 root 和一个表示目标和的整数 targetSum ，判断该树中是否存在
 * 根节点到叶子节点的路径，这条路径上所有节点值相加等于目标和 targetSum 。
 *
 * 注意：叶子节点是没有子节点的节点
 *
 * @限制条件：
 *
 * NULL
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
  bool hasPathSum(TreeNode *root, int targetSum) {
    if (!root) {
      return false;
    }
    if (root->left == nullptr && root->right == nullptr) {
      return targetSum == root->val;
    } else {
      return (hasPathSum(root->left, targetSum - root->val) ||
              hasPathSum(root->right, targetSum - root->val));
    }
  }
};

int main(int argc, char const *argv[]) { return 0; }
