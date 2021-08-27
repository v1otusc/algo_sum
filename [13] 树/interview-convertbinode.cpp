/*
 * @Description:
 *
 * 输入二叉搜索树，返回一个二叉搜索树，仅有右子树
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
  TreeNode* dummy = new TreeNode(-1);
  TreeNode* cur = dummy;

 public:
  // 中序遍历
  void dfs(TreeNode* node) {
    if (!node) return;
    dfs(node->left);
    // node->left = nullptr;
    node->left = nullptr;
    cur->right = node;
    cur = node;
    dfs(node->right);
  }

  TreeNode* convertBiNode(TreeNode* root) {
    dfs(root);
    return dummy->right;
  }
};

int main(int argc, char const* argv[]) { return 0; }