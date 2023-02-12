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
 * dfs + 策略问题
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
  bool btreeGameWinningMove(TreeNode* root, int n, int x) {
    TreeNode* node = find(root, x);
    int left_size = get_subtree_size(node->left);
    if (left_size >= ((n + 1) / 2)) {
      return true;
    }
    int right_size = get_subtree_size(node->right);
    if (right_size >= ((n + 1) / 2)) {
      return true;
    }

    int remain = n - 1 - left_size - right_size;
    return remain >= ((n + 1) / 2);
  }

  TreeNode* find(TreeNode* root, int x) {
    if (root == nullptr) {
      return nullptr;
    }

    if (root->val == x) {
      return root;
    }
    // 递归的思想
    TreeNode* res = find(root->left, x);
    if (res == nullptr) {
      return find(root->right, x);
    } else {
      return res;
    }
  }

  int get_subtree_size(TreeNode* node) {
    if (node == nullptr) return 0;
    return 1 + get_subtree_size(node->left) + get_subtree_size(node->right);
  }
};

int main(int argc, char const* argv[]) { return 0; }
