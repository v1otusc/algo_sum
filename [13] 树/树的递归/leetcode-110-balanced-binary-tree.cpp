/*
 * @Description:
 *
 * 判断一个二叉树是否平衡
 * 树平衡的定义是，对于树上的任意节点，其两侧节点的最大深度的差值不得大于 1
 *
 * @题目思路：
 *
 * 需要先处理子树的深度再进行比较；
 * 如果我们在处理子树时发现其已经不平衡了，则可以返回一个就 -1，避免多余的判断
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-08 10:33:32
 * @FilePath: /algo_sum/[13] 树/树的递归/leetcode-110-balanced-binary-tree.cpp
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
  bool isBalanced(TreeNode* root) { return helper(root) != -1; }

  int helper(TreeNode* root) {
    if (!root) {
      return 0;
    }
    int left = helper(root->left);
    int right = helper(root->right);
    if (left == -1 || right == -1 || abs(left - right) > 1) {
      return -1;
    }
    return 1 + max(left, right);
  }
};

int main(int argc, char const* argv[]) { return 0; }
