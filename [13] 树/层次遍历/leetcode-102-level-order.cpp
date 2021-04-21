/*
 * @Description:
 *
 * 给你一个二叉树，请你返回其按层序遍历得到的节点值。
 *（即逐层地，从左到右访问所有节点）。
 *
 * @题目思路：
 *
 * 广度优先搜索，使用队列
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-21 20:34:45
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
  vector<vector<int>> levelOrder(TreeNode *root) {
    vector<vector<int>> res;
    if (root == nullptr) {
      return res;
    }
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) {
      // 每一层的节点个数,在push之前算出来
      int count = q.size();
      // ----------------------------
      vector<int> row;
      for (int i = 0; i < count; i++) {
        TreeNode *node = q.front();
        q.pop();
        row.push_back(node->val);
        if(node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      res.push_back(row);
    }
    return res;
  }
};

int main(int argc, char const *argv[]) { return 0; }
