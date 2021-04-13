/*
 * @Description:
 *
 * 给定一个二叉查找树和两个整数 L 和 R， 且 L < R
 * 试修剪此二叉查找树，,使得修剪后所有节点的值都在[L, R]
 * 的范围内
 *
 * @输入输出说明：
 *
 * 输入是一个二叉查找树和两个整数 L 和 R,输出一个被修剪好的二叉查找树。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * easy
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

using namespace std;

class Solution {
 public:
  TreeNode *trimBST(TreeNode *root, int L, int R) {
    if (!root) {
      return root;
    }
    if (root->val > R) {
      return trimBST(root->left, L, R);
    }
    if (root->val < L) {
      return trimBST(root->right, L, R);
    }
    root->left = trimBST(root->left, L, R);
    root->right = trimBST(root->right, L, R);
    return root;
  }
};

int main(int argc, char const *argv[]) { return 0; }
