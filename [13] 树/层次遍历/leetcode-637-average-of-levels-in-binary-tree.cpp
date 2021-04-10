/*
 * @Description:
 *
 * 给定一个二叉树，求每一层的节点值的平均数
 *
 * @输入输出说明：
 *
 * 输入是一个二叉树,输出是一个一维数组,表示每层节点值的平均数。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 利用广度优先搜索
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
  vector<double> averageOfLevels(TreeNode *root) {
    vector<double> ans;
    if (!root) {
      return ans;
    }

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty()) {
      // 每一层的 count 在之前就算好了
      int count = q.size();
      double sum = 0;
      // 每一层遍历
      for (int i = 0; i < count; ++i) {
        TreeNode *node = q.front();
        q.pop();
        sum += node->val;
        if (node->left) {
          q.push(node->left);
        }
        if (node->right) {
          q.push(node->right);
        }
      }
      ans.push_back(sum / count);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) { return 0; }
