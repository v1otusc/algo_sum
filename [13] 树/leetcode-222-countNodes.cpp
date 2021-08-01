/*
 * @Description:
 *
 * 完全二叉树的节点个数
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
  int countNodes(TreeNode *root) {
    // 最左边和最右边的高度
    int hl = 0, hr = 0;
    TreeNode *l_root = root;
    TreeNode *r_root = root;
    while (l_root) {
      l_root = l_root->left;
      hl++;
    }
    while (r_root) {
      r_root = r_root->right;
      hr++;
    }
    if (hl == hr) {
      return (int)pow(2, hr) - 1;
    }
    // 如果左右高度不同，则按照普通二叉树计算
    return 1 + countNodes(root->left) + countNodes(root->right);
  }
};

int main(int argc, char const *argv[]) { return 0; }