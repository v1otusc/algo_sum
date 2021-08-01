/*
 * @Description:
 *
 * 某二叉树中任一节点的左右子树深度相差不超过1，那么它就是一棵平衡二叉树
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
  bool isBalanced(TreeNode* root) {
    if (root == nullptr) {
      return true;
    }
    return abs(height(root->left) - height(root->right)) <= 1 &&
           isBalanced(root->left) && isBalanced(root->right);
  }

  int height(TreeNode* node) {
    if (node == nullptr) return 0;
    // if (node->right == nullptr && node->left == nullptr) return 1;
    return 1 + max(height(node->left), height(node->right));
  }
};

int main(int argc, char const* argv[]) { return 0; }