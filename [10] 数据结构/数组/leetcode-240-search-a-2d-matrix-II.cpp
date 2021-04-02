/*
 * @Description:
 *
 给定一个二维矩阵,已知每行和每列都是增序的,尝试设计一个快速搜索一个数字是否在矩
 阵中存在的算法。
 *
 * @输入示例：
 *
 * Input: matrix =
[ [1, 4, 7, 11, 15],
[2, 5, 8, 12, 19],
[3, 6, 9, 16, 22],
[10, 13, 14, 17, 24],
[18, 21, 23, 26, 30]], target = 5
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 输入是一个二维整数矩阵,和一个待搜索整数。输出是一个布尔值,表示这个整数是否存在
 于矩阵中。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 这道题有一个简单的技巧:我们可以从右上角开始查找,若当前值大于待搜索值,我们向左
 移动一位;若当前值小于待搜索值,我们向下移动一位。如果最终移动到左下角时仍不等于待搜
 索值,则说明待搜索值不存在于矩阵中。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    int m = matrix.size();
    int n = matrix[0].size();
    if (m == 0 || n == 0) {
      return false;
    }
    int i = 0;
    int j = n - 1;
    while (i < m && j >= 0) {
      if (matrix[i][j] == target) {
        return true;
      } else if (matrix[i][j] < target) {
        i++;
      } else {
        j--;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) { return 0; }
