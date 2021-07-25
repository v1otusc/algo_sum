/*
 * @Description:
 *
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果
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
 *
 *
 * @题目思路：
 *
 * 根据二叉搜索树的性质进行递归
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  // 左闭右开的形式
  bool verify(vector<int>& postorder, int left, int right) {
    // 注意返回条件
    if (left >= right) return true;
    int r_start = left;
    for (; r_start < right - 1; ++r_start) {
      if (postorder[r_start] > postorder[right - 1]) {
        break;
      }
    }
    for (int i = r_start; i < right - 1; ++i) {
      if (postorder[i] < postorder[right - 1]) {
        return false;
      }
    }

    return verify(postorder, left, r_start) &&
           verify(postorder, r_start, right - 1);
  }
  bool verifyPostorder(vector<int>& postorder) {
    // 注意返回条件
    if (postorder.size() <= 1) return true;
    return verify(postorder, 0, postorder.size());
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  vector<int> order{4, 6, 7, 9};
  bool res = s.verifyPostorder(order);
  cout << (res ? "True" : "False") << endl;
  return 0;
}