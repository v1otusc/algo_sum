/*
 * @Description:
 *
 * 给定一个整数二叉树和一些整数，求删掉这些整数对应节点后，剩余的子树
 *
 * @输入输出说明：
 *
 输入是一个整数二叉树和一个一维整数数组,输出一个数组,每个位置存储一个子树(的根
 节点)。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 一个节点被删除时的情况：
 1.如果该节点是根节点，形成左右两个子树，此时递归左右子树
 2.如果该节点不是根节点，那么需要修改其父节点指向自己的指针为空，并且递归左右子树。

 一个节点一旦被删除，那么其左右孩子就是新的树的根节点。
 如果一个节点是根节点，并且不被删除的情况下，才会放入结果中。
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
  vector<TreeNode *> delNodes(TreeNode *root, vector<int> &to_delete) {
    vector<TreeNode *> res;
    helper(root, true, res, to_delete);
    return res;
  }

  // 传递参数为 TreeNode *& node
  // 当传递指针时，指针指向的数据是可以改变，而指针本身是不可以改变的。
  // 指针的引用，相当于指针的指针。作为参数传递时，这样指针的数值是可以改变的
  void helper(TreeNode *&node, bool is_root, vector<TreeNode *> &res,
              vector<int> &to_delete) {
    if (!node) return;
    // 判断是否删除当前节点
    bool is_del = del_cur_node(node, to_delete);
    // 如果删除，其左右子节点可以作为根节点
    helper(node->left, is_del, res, to_delete);
    helper(node->right, is_del, res, to_delete);
    // 可以作为主节点
    if (is_root && !is_del) {
      res.push_back(node);
    }
    // 如果不是根节点，但是被删除了
    if (!node && is_del) {
      node = nullptr;
    }
  }

  bool del_cur_node(TreeNode *node, vector<int> &to_delete) {
    for (auto val : to_delete) {
      if (node->val == val) {
        return true;
      }
    }
    return false;
  }
};

int main(int argc, char const *argv[]) { return 0; }
