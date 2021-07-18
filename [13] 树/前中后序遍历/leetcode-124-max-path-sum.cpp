/*
 * @Description:
 *
 *
 路径被定义为一条从树中任意节点出发，沿父节点-子节点连接，达到任意节点的序列。同一个节点在一条路径序列中
 至多出现一次 。该路径 至少包含一个 节点，且不一定经过根节点。
 *
 * @输入示例：
 *
 * 二叉树根节点
 *
 * @输出实例：
 *
 * 返回的最大值
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
 * 后序遍历
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
  int max_sum = INT_MIN;

 public:
  int one_side_max(TreeNode *node) {
    if (node == nullptr) return 0;
    int left = max(0, one_side_max(node->left));
    int right = max(0, one_side_max(node->right));

    max_sum = max(max_sum, left + right + node->val);

    // 返回节点贡献的最大值
    return max(left, right) + node->val;
  }

  int maxPathSum(TreeNode *root) {
    one_side_max(root);
    return max_sum;
  }
};

int main(int argc, char const *argv[]) { return 0; }
