/*
 * @Description:
 *
 * 实现二叉树的前序遍历
 *
 * @输入示例：
 *
 * 输入一个二叉树，输出一个数组，为二叉树前序遍历的结果
 *
 * @题目思路：
 *
 * 不使用递归则使用栈
 * 递归的本质就是栈调用
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

// 使用递归的写法
/*class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    preorder(root, res);
    return res;
  }

  void preorder(TreeNode *root, vector<int> &res) {
    if (!root) {
      return;
    }
    res.push_back(root->val);
    preorder(root->left, res);
    preorder(root->right, res);
  }
};*/

// 使用栈的写法
class Solution {
 public:
  vector<int> preorderTraversal(TreeNode *root) {
    vector<int> res;
    if (!root) {
      return res;
    }
    stack<TreeNode *> s;
    s.push(root);
    while (!s.empty()) {
      TreeNode *node = s.top();
      s.pop();
      res.push_back(node->val);
      // 先右后左，保证左子树先遍历
      // 真精
      if (node->right) {
        s.push(node->right);
      }
      if (node->left) {
        s.push(node->left);
      }
    }
    return res;
  }
};

int main(int argc, char const *argv[]) { return 0; }
