/*
 * @Description:
 *
 * 求一个二叉树的最大深度
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-07 22:13:32
 * @FilePath: /algo_sum/[13] 树/树的递归/leetcode-104-maximum-depth-of-binary-tree.cpp
 * 树/树的递归/leetcode-104-maximum-depth-of-binary-tree.cpp
 * 树/树的递归/leetcode-104-maximum-depth-of-binary-tree.cpp
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
  int maxDepth(TreeNode* root) {
    return root ? 1 + max(maxDepth(root->left), maxDepth(root->right)) : 0;
  }
};

int main(int argc, char const* argv[]) { return 0; }
