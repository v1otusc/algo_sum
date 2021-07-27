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
 * 二叉树的根节点最小 ->
 * 深度优先遍历，找出严格大于根节点的值
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

/*class Solution {
 public:
  void dfs(TreeNode *node, int &ans, const int &root_val) {
    if (!node) {
      return;
    }
    if (ans != -1 && node->val >= ans) {
      return;
    }
    // node->val < ans 的情况了
    if (node->val > root_val) {
      ans = node->val;
      return;
    }
    dfs(node->left, ans, root_val);
    dfs(node->left, ans, root_val);
  }

  int findSecondMinimumValue(TreeNode *root) {
    int ans = -1;
    int root_val = root->val;
    dfs(root, ans, root_val);
    return ans;
  }
};*/

class Solution {
 public:
  // 改成小顶堆
  priority_queue<int,vector<int>, greater<int>> q;
  int findSecondMinimumValue(TreeNode *root) {
    if (!root) return -1;
    int min = root->val;
    int ans = -1;

    queue<TreeNode *> tq;
    tq.push(root);
    while (!tq.empty()) {
      int sz = tq.size();
      for (int i = 0; i < sz; ++i) {
        TreeNode *node = tq.front();
        tq.pop();
        q.push(node->val);
        if (node->left) tq.push(node->left);
        if (node->right) tq.push(node->right);
      }
    }

    if (q.size() < 2) return ans;
    while (!q.empty()) {
      if (q.top() > min) {
        ans = q.top();
        break;
      }
      q.pop();
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) { return 0; }
