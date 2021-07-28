/*
 * @Description:
 *
 * 给定一个二叉树(具有根节点 root)，一个目标节点 target 和一个整数值 K
 *
 * 返回到目标节点 target 距离为 K 的所有节点的值的列表
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
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
 public:
  vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
    dfs(root);
    calc(target, k);
    return ret;
  }

 private:
  vector<int> ret;
  // 节点 —— 对应的父节点
  unordered_map<TreeNode*, TreeNode*> mp;
  // visited?
  unordered_set<TreeNode*> se;
  void calc(TreeNode* t, int k) {
    if (!t || se.count(t)) return;
    se.insert(t);
    if (k == 0) {
      ret.push_back(t->val);
      return;
    }
    calc(t->left, k - 1);
    calc(t->right, k - 1);
    // root 没有父节点
    if (mp.count(t)) calc(mp[t], k - 1);
    return;
  }
  // 构建 unordered_map 节点 —— 对应的父节点
  void dfs(TreeNode* t) {
    if (!t) return;
    if (t->left) mp[t->left] = t, dfs(t->left);
    if (t->right) mp[t->right] = t, dfs(t->right);
    return;
  }
};

int main(int argc, char const* argv[]) { return 0; }
