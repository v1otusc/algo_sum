/*
 * @Description:
 *
 * 在二叉查找树中删除某个值
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
  TreeNode *deleteNode(TreeNode *root, int key) {
    if (root == nullptr) return root;
    if (root->val == key) {
      if (root->left == nullptr) return root->right;
      if (root->right == nullptr) return root->left;
      // 情况 3 此节点有两个根节点
      // 获取左边节点的最大值
      TreeNode *left_max = get_max(root->left);
      root->val = left_max->val;
      root->left = deleteNode(root->left, left_max->val);

    } else if (root->val > key) {
      root->left = deleteNode(root->left, key);
    } else {
      root->right = deleteNode(root->right, key);
    }
    return root;
  }

  TreeNode *get_max(TreeNode *root) {
    while (root->right) root = root->right;
    return root;
  }
};

int main(int argc, char const *argv[]) { return 0; }
