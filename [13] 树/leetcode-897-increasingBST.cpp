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
  void inorder(TreeNode *node, vector<int> &res) {
    if (node == nullptr) {
      return;
    }
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
  }

 public:
  TreeNode *increasingBST(TreeNode *root) {
    vector<int> res;
    inorder(root, res);

    TreeNode *head = new TreeNode(-1);
    TreeNode *cur = head;
    for (auto value : res) {
      cur->right = new TreeNode(value);
      cur = cur->right;
    }
    return head->right;
  }
};

int main(int argc, char const *argv[]) { return 0; }
