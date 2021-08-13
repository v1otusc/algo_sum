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
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

class Solution {
 private:
  // 单个路径
  vector<int> path;
  vector<vector<int>> ans;

 public:
  vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    path.clear();
    ans.clear();
    if (root == nullptr) return ans;
    // 把根节点放进路径
    path.push_back(root->val);
    dfs(root, targetSum - root->val);
    return ans;
  }

  void dfs(TreeNode* node, int target) {
    if (!node->left && !node->right && target == 0) {
      ans.push_back(path);
      return;
    }

    // 遇到叶子节点却没有找到合适的路径
    if (!node->left && !node->right) return;
    
    // 有才放
    if (node->left) {
      path.push_back(node->left->val);
      target -= node->left->val;
      dfs(node->left, target);
      // 回溯的过程
      target += node->left->val;
      path.pop_back();
    }

    if (node->right) {
      path.push_back(node->right->val);
      target -= node->right->val;
      dfs(node->right, target);
      // 回溯的过程
      target += node->right->val;
      path.pop_back();
    }
    return;
  }
};

int main(int argc, char const* argv[]) { return 0; }