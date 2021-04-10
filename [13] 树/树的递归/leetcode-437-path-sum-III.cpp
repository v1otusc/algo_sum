/*
 * @Description:
 *
 * 给定一个整数二叉树，求有多少条路径节点值的和等于给定值。
 * 路径不需要从根节点开始，也不需要在叶子节点结束，但是路径方向必须是向下的（只能从父节点到子节点）。
 *
 * @输入输出说明：
 *
 * 输入一个二叉树和一个给定整数,输出一个整数,表示有多少条满足条件的路径。
 *
 * @题目思路：
 *
 * 递归每个节点时，需要分情况考虑：
 * 1 如果选取该节点加入路径,则之后必须继续加入连续节点，或停止加入节点
 * 2 如果不选取该节点加入路径，则对其左右子节点重新进行考虑。
 * 因此一个方便的方法是我们创建一个辅函数,专门用来计算连续加入节点的路径。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-04-09 14:31:01
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
  int pathSum(TreeNode *root, int sum) {
    // 三类 path
    // 分别表示加入根节点，加入根节点的左子节点，加入根节点的右子节点
    return root ? pathSumStartWithRoot(root, sum) + pathSum(root->left, sum) +
                      pathSum(root->right, sum)
                : 0;
  }

  // 辅函数，表示考虑节点，并连续加入其子节点
  int pathSumStartWithRoot(TreeNode *root, int sum) {
    if (!root) {
      return 0;
    }
    int count = (root->val == sum) ? 1 : 0;
    count += pathSumStartWithRoot(root->left, sum - root->val);
    count += pathSumStartWithRoot(root->right, sum - root->val);
    return count;
  }
};

int main(int argc, char const *argv[]) { return 0; }
