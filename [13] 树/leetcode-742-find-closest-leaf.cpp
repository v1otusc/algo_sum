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
 * 首先 dfs 获取每一个节点的父节点
 * 然后 bfs 获取结果
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
 private:
  // key 是节点，value 是与该节点相连的节点（包括父节点和子节点）
  // 不要有 nullptr
  unordered_map<TreeNode *, vector<TreeNode *>> graph;

 public:
  // 遍历到的节点，对应的父节点, 不要有 nullptr
  void dfs(TreeNode *node, TreeNode *p) {
    if (node == nullptr) return;
    if (p != nullptr) {
      graph[p].push_back(node);
      graph[node].push_back(p);
    }
    dfs(node->left, node);
    dfs(node->right, node);
  }

  int findClosestLeaf(TreeNode *root, int k) {
    graph.clear();
    if (root == nullptr) {
      return -1;
    }

    // 只有 root 一个节点
    // 只有 root-> val == k 的时候才会返回
    if ((root->left == nullptr) && (root->right == nullptr)) {
      if (root->val == k)
        return root->val;
      else
        return -1;
    }

    // p 是当前节点的父节点，当前是 root 节点
    TreeNode *p = nullptr;
    dfs(root, p);

    TreeNode *start = nullptr;

    // 找到 start->val == k
    for (auto it : graph) {
      // 找到 val 值为 k 的节点
      if (it.first->val == k) {
        start = it.first;
        break;
      }
    }

    queue<TreeNode *> q;
    set<TreeNode *> vis;
    q.push(start);
    vis.insert(start);

    while (!q.empty()) {
      TreeNode *t = q.front();
      q.pop();

      // 要求的是叶子节点
      if (t->left == nullptr && t->right == nullptr) return t->val;

      vector<TreeNode *> v = graph[t];
      for (auto &it : v) {
        if (!vis.count(it)) {
          q.push(it);
          vis.insert(it);
        }
      }
    }
    return -1;
  }
};

int main(int argc, char const *argv[]) { return 0; }
