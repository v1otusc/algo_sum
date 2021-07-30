/*
 * @Description:
 *
 * 完全二叉树，偶数行为逆序
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
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int get_reverse(int label, int row) {
    // 从左到右编号变成从右到左
    return (1 << row - 1) + (1 << row) - 1 - label;
  }
  vector<int> pathInZigZagTree(int label) {
    int row = 1;
    // 每一行的首个标号
    int row_start = 1;
    while (row_start * 2 <= label) {
      row++;
      row_start *= 2;
    }

    // 技巧，首先翻转一次
    if (row % 2 == 0) {
      label = get_reverse(label, row);
    }
    vector<int> path;
    while (row > 0) {
      if (row % 2 == 0) {
        path.push_back(get_reverse(label, row));
      } else {
        path.push_back(label);
      }
      row--;
      // 找到父节点
      label >>= 1;
    }
    reverse(path.begin(), path.end());
    return path;
  }
};

int main(int argc, char const* argv[]) { return 0; }
