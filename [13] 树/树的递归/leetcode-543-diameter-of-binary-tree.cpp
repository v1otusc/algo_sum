/*
 * @Description:
 *
 * 求一个二叉树的最长直径。这条路径可能穿过也可能不穿过根结点。
 * 注意：两结点之间的路径长度是以它们之间边的数目表示。
 * 例如有最多有四个节点，他们之间的最长直径为 3
 *
 * @输入输出说明：
 *
 * 输入是一个二叉树,输出一个整数,表示最长直径。
 *
 * @题目思路：
 *
 * 解题时要注意,在我们处理某个子树时,我们更新的最长直径值和递归返回的值是不同的。
 * 最长直径值为经过该子树根节点的最长直径(两侧长度)；
 * 函数返回值是以该子树根节点为端点的最长直径值(一侧长度)
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
  int diameterOfBinaryTree(TreeNode *root) {
    int diameter = 0;
    // diameter 是最长直径值，而 helper 本身也会返回值
    helper(root, diameter);
    return diameter;
  }

  int helper(TreeNode *node, int &diameter) {
    if (!node) {
      return 0;
    }
    int l = helper(node->left, diameter);
    int r = helper(node->right, diameter);
    diameter = max(l + r, diameter);
    return max(l, r) + 1;
  }
};

int main(int argc, char const *argv[]) { return 0; }
