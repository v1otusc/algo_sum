/*
 * @Description:
 *
 * 实现一个二叉搜索树迭代器类BSTIterator
 * ，表示一个按中序遍历二叉搜索树（BST）的迭代器：
 *
 * - BSTIterator(TreeNode root) 初始化 BSTIterator 类的一个对象。BST 的根节点
 *   root 会作为构造函数的一部分给出。指针应初始化为一个不存在于 BST
 *   中的数字，且该数字小于 BST 中的任何元素。
 * - boolean hasNext() 如果向指针右侧遍历存在数字，则返回 true ；否则返回 false
 * - int next()将指针向右移动，然后返回指针处的数字。
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
 * 注意，指针初始化为一个不存在于 BST 中的数字，所以对 next() 的首次调用将返回
 * BST 中的最小元素。
 *
 * 你可以假设 next() 调用总是有效的，也就是说，当调用 next() 时，BST
 * 的中序遍历中至少存在一个下一个数字。
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

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode* left, TreeNode* right)
      : val(x), left(left), right(right) {}
};

using namespace std;

class BSTIterator {
 private:
  void inorder(TreeNode* root, vector<int>& res) {
    if (!root) {
      return;
    }
    inorder(root->left, res);
    res.push_back(root->val);
    inorder(root->right, res);
  }

  vector<int> inorderTraversal(TreeNode* root) {
    vector<int> res;
    inorder(root, res);
    return res;
  }

  vector<int> arr;
  int idx;

 public:
  BSTIterator(TreeNode* root) : idx(0), arr(inorderTraversal(root)) {}

  int next() { return arr[idx++]; }

  bool hasNext() { return (idx < arr.size()); }
};

int main(int argc, char const* argv[]) { return 0; }
