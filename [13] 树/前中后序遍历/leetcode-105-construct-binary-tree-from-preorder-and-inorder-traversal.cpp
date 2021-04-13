/*
 * @Description:
 *
 * 给定一个二叉树的前序遍历和中序遍历结果，尝试复原这个树。
 * 已知树里不存在重复值的节点
 *
 * @输入示例：
 *
 * preorder = [4, 9, 20, 15, 7]
 * inorder = [9, 4, 15, 20, 7]
 *
 * @输出实例：
 *
 *   4
 *  / \
 * 9  20
 *   /  \
 *  15  7
 *
 * @输入输出说明：
 *
 * 输入是两个一维数组,分别表示树的前序遍历和中序遍历结果;输出是一个二叉树。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 我们通过本题的样例讲解一下本题的思路。前序遍历的第一个节点是 4,意味着 4
 * 是根节点。我们在中序遍历结果里找到 4 这个节点,根据中序遍历的性质可以得出,4
 * 在中序遍历数组位置的左子数组为左子树,节点数为 1,对应的是前序排列数组里 4
 * 之后的 1 个数字(9); 4
 * 在中序遍历数组位置的右子数组为右子树，节点数为3，,对应的是前序排列数组里最后的
 * 3 个数字。有了这些信息,我们就可以对左子树和右子树进行递归复原了。
 * 为了方便查找数字的位置,我们可以使用哈希表预处理中序遍历的结果
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
  unordered_map<int, int> hash;

 public:
  TreeNode *buildTree(vector<int> &preorder, vector<int> &inorder) {
    if (preorder.empty()) {
      return nullptr;
    }
    int n = preorder.size();
    // 利用 hash map 预处理中序遍历的结果
    // 帮助快速定位根节点
    for (size_t i = 0; i < inorder.size(); i++) {
      hash[inorder[i]] = i;
    }
    return helper(preorder, inorder, 0, n - 1, 0, n - 1);
  }
  TreeNode *helper(const vector<int> &preorder, const vector<int> &inorder,
                   int preorder_left, int preorder_right, int inorder_left,
                   int inorder_right) {
    if (preorder_left > preorder_right) {
      return nullptr;
    }
    // 前序遍历中的第一个节点就是根节点
    int preorder_root = preorder_left;
    // 在中序遍历中定位根节点
    int inorder_root = hash[preorder[preorder_root]];

    // 目的就是把根节点建立出来
    TreeNode *root = new TreeNode(preorder[preorder_root]);
    // 得到左子树中的节点数目
    int size_left_subtree = inorder_root - inorder_left;
    // 递归地构造左子树，并连接到根节点
    // 先序遍历中「从 左边界+1 开始的
    // size_left_subtree」个元素就对应了中序遍历中「从 左边界 开始到
    // 根节点定位-1」的元素
    root->left = helper(preorder, inorder, preorder_left + 1,
                        preorder_left + size_left_subtree, inorder_left,
                        inorder_root - 1);
    // 递归地构造右子树，并连接到根节点
    // 先序遍历中「从 左边界+1+左子树节点数目 开始到
    // 右边界」的元素就对应了中序遍历中「从 根节点定位+1 到 右边界」的元素
    root->right =
        helper(preorder, inorder, preorder_left + size_left_subtree + 1,
               preorder_right, inorder_root + 1, inorder_right);
    return root;
  }
};

int main(int argc, char const *argv[]) { return 0; }
