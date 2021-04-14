/*
 * @Description:
 *
 * 给定一个二叉查找树，已知有两个节点不小心被交换了，试复原此树
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
 * 输入是一个被误交换两个节点的二叉查找树,输出是改正后的二叉查找树。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用中序遍历这个二叉查找树,同时设置一个 prev
 * 指针,记录当前节点中序遍历时的前节点，如果当前节点大于 prev
 * 节点的值,说明需要调整次序。
 * 有一个技巧是如果遍历整个序列过程中只出现了一次次序错误,说明就是这两个相邻节点进行了交换
 * 如果出现了两次次序错误，那就需要交换这两个节点，两个节点不相邻。
 *
 * 一定要记住，对 BST 进行中序遍历的结果即为排好序的数组
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
  void recoverTree(TreeNode *root) {
    vector<int> nums;
    inorder(root, nums);
    pair<int, int> swapped = findTwoSwapped(nums);
    recover(root, 2, swapped.first, swapped.second);
  }

  void inorder(TreeNode *root, vector<int> &nums) {
    if (root == nullptr) {
      return;
    }
    inorder(root->left, nums);
    nums.push_back(root->val);
    inorder(root->right, nums);
  }

  pair<int, int> findTwoSwapped(vector<int> &nums) {
    int x = -1;
    int y = -1;
    for (int i = 0; i < nums.size() - 1; ++i) {
      // 发生了错误
      if (nums[i + 1] < nums[i]) {
        y = nums[i + 1];
        if (x == -1) {
          x = nums[i];
        } else
          break;
      }
    }
    pair<int, int> res{x, y};
    return res;
  }

  void recover(TreeNode *root, int count, int x, int y) {
    if (root != nullptr) {
      if (root->val == x || root->val == y) {
        root->val = (root->val == x) ? y : x;
        if (--count == 0) return;
      }
      recover(root->left, count, x, y);
      recover(root->right, count, x, y);
    }
  }
};

int main(int argc, char const *argv[]) { return 0; }
