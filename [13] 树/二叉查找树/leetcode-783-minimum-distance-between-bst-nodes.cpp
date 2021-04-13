/*
 * @Description:
 *
 * 给你一个二叉搜索树的根节点 root，返回树中任意两不同节点值之间的最小差值。
 *
 * @题目思路：
 *
 * 中序遍历排列好数组，然后逐个比较
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-13 20:04:00
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
  vector<int> ordered;
  int minDiffInBST(TreeNode *root) {
    int ans = INT_MAX;
    inorder(root, ordered);
    for (int i = 0; i < ordered.size() - 1; ++i) {
      ans = min(ans, ordered[i + 1] - ordered[i]);
    }
    return ans;
  }
  // 进行中序遍历，遍历后的结果即为排好序的结果
  void inorder(TreeNode *root, vector<int> &ordered) {
    if (!root) return;
    if (root->left) {
      inorder(root->left, ordered);
    }
    ordered.push_back(root->val);
    if (root->right) {
      inorder(root->right, ordered);
    }
  }
};

int main(int argc, char const *argv[]) { return 0; }
