/*
 * @Description:
 *
 * 判断一个二叉树，输出一个布尔值，表示该树是否对称
 *
 * @输入输出说明：
 *
 * 输入一个二叉树,输出一个布尔值,表示该树是否对称。
 *
 * @题目思路：
 *
 * 将判断两个子树是否相等或对称的题目解法叫做四步法：
 *
 * (1) 如果两个子树都为空指针,则它们相等或对称
 * (2) 如果两个子树只有一个为空指针,则它们不相等或不对称
 * (3) 如果两个子树根节点的值不相等,则它们不相等或不对称
 * (4) 根据相等或对称要求,进行递归处理。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-08 14:59:16
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
  bool isSymmetric(TreeNode *root) {
    return root ? isSymmetric(root->left, root->right) : true;
  }

  bool isSymmetric(TreeNode *left, TreeNode *right) {
    // 两个子树都是空指针
    if (!left && !right) {
      return true;
    }

    // 两个子树只有一个空指针 --
    // 此判断一定要在判断两个子树是否都是空指针之后进行
    if (!left || !right) {
      return false;
    }

    // 如果两个子树根节点的值不相等,则它们不相等或不对称
    if (left->val != right->val) {
      return false;
    }

    // 进行递归处理
    return isSymmetric(left->left, right->right) &&
           isSymmetric(left->right, right->left);
  }
};

int main(int argc, char const *argv[]) { return 0; }
