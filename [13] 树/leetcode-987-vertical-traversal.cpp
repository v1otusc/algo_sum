/*
 * @Description:
 *
 * 对位于 (row, col) 的每个节点而言，其左右子节点分别位于(row+1, col-1)和
 * (row+1, col+1) 。树的根节点位于(0,0)
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
 * 从最左边的列开始直到最右边的列结束，按列索引每一列上的所有节点，形成一个按出现位置从上到下的有序列表。
 * 如果同行同列上有多个节点，则按节点的值从小到大进行排序
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 硬做
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
  // col —— {row, node->val}
  // 默认按照 col 从小到大排序
  // 默认按照 row 从小到大排序
  map<int, map<int, vector<int>>> mp;

 public:
  void dfs(TreeNode *node, int row, int col) {
    if (!node) return;
    mp[col][row].push_back(node->val);
    dfs(node->left, row + 1, col - 1);
    dfs(node->right, row + 1, col + 1);
  }
  vector<vector<int>> verticalTraversal(TreeNode *root) {
    dfs(root, 0, 0);
    vector<vector<int>> ans;
    for (auto m : mp) {
      vector<int> tmp;
      for (auto &mm : m.second) {
        if (mm.second.size() > 0) {
          sort(mm.second.begin(), mm.second.end());
          for (auto &mmm : mm.second) {
            tmp.push_back(mmm);
          }
        }
      }
      ans.push_back(tmp);
    }
    return ans;
  }
};

int main(int argc, char const *argv[]) { return 0; }
