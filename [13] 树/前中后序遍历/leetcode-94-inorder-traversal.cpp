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

/* 递归的方法
class Solution_Recursion {
 public:
  void inorder(TreeNode *node, vector<int> &res) {
    if (node == nullptr) return;
    inorder(node->left, res);
    res.push_back(node->val);
    inorder(node->right, res);
  }

  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }
};*/

class Solution {
 public:
  vector<int> inorderTraversal(TreeNode *root) {
    vector<int> res;
    stack<TreeNode *> stk;
    // 前序遍历，出栈顺序：根左右; 入栈顺序：右左根
    // 中序遍历，出栈顺序：左根右; 入栈顺序：右根左
    // 后序遍历，出栈顺序：左右根; 入栈顺序：根右左
    while (root != nullptr || !stk.empty()) {
      while (root != nullptr) {
        // 先根后左入栈
        stk.push(root);
        root = root->left;
      }
      // 此时最深存在的左子节点出栈
      root = stk.top();
      stk.pop();
      res.push_back(root->val);
      // 如果 root->right 存在，右入栈，再出栈
      root = root->right;
    }
    return res;
  }
};

int main(int argc, char const *argv[]) { return 0; }
