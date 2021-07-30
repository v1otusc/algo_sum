/*
 * @Description:
 *
 * 在二叉搜索树中插入某个值
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
  TreeNode *insertIntoBST(TreeNode *root, int val) {
    if (root == nullptr) return new TreeNode(val);
    if (root->val == val) return root;
    if (root->val < val) {
      root->right = insertIntoBST(root->right, val);
    } else if (root->val > val) {
      root->left = insertIntoBST(root->left, val);
    }
    return root;
  }
};

int main(int argc, char const *argv[]) { return 0; }