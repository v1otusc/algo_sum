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
 * 使用 bfs, 中规中矩
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

/* bfs 版本，遇到 node->val == arr[count]，才 push(node->left) 和
push(node->right)
/* 简直太巧妙了
class Solution {
 public:
  bool isValidSequence(TreeNode *root, vector<int> &arr) {
    if (root == nullptr) {
      return (arr.size() > 0) ? false : true;
    }

    int n = arr.size();
    int count = 0;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty()) {
      int sz = q.size();
      for (int i = 0; i < sz; ++i) {
        TreeNode *node = q.front();
        q.pop();
        if (node->val == arr[count]) {
          if (count == n - 1) {
            return (!node->left) && (!node->right);
          } else {
            if (node->left) q.push(node->left);
            if (node->right) q.push(node->right);
          }
        }
      }
      count++;
    }
    return false;
  }
};*/

// dfs 版本，暴搜
class Solution {
 public:
  bool isValidSequence(TreeNode *root, vector<int> &arr) {
    dfs(root, {});
    return memo.count(arr);
  }

 private:
  set<vector<int>> memo;
  void dfs(TreeNode *root, vector<int> cur) {
    if (!root) {
      return;
    } else if (!root->left && !root->right) {
      cur.push_back(root->val);
      memo.insert(cur);
      return;
    }

    cur.push_back(root->val);
    dfs(root->left, cur);
    dfs(root->right, cur);
  }
};

int main(int argc, char const *argv[]) { return 0; }
