/*
 * @Description:
 *
 * 给定一个整数二叉树，,求有多少条路径节点值的和等于给定值。
 *
 * @输入输出说明：
 *
 * 输入一个二叉树和一个给定整数,输出一个整数,表示有多少条满足条件的路径。
 *
 * @题目思路：
 *
 * 
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-08 11:22:04
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
  int pathSum(TreeNode* root, int sum) {
    
  }
};

int main(int argc, char const *argv[]) { return 0; }
