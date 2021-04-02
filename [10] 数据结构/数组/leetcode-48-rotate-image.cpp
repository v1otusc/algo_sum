/*
 * @Description:
 *
 给定一个 n × n 的二维矩阵 matrix 表示一个图像。请你将图像顺时针旋转 90 度。
 你必须在 原地 旋转图像，这意味着你需要直接修改输入的二维矩阵。请不要
 使用另一个矩阵来旋转图像。
 *
 * @输入示例：
 *
 * matrix = [[1,2,3],[4,5,6],[7,8,9]]
 *
 * @输出实例：
 *
 * [[7,4,1],[8,5,2],[9,6,3]]
 *
 * @输入输出说明：
 *
 * 输入和输出都是个二维整数矩阵
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 把图画出来就可以解决
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    int temp = 0;
    int n = matrix.size() - 1;
    for (int i = 0; i <= n / 2; ++i) {
      for (int j = i; j < n - i; ++j) {
        temp = matrix[j][n - i];
        matrix[j][n - i] = matrix[i][j];
        matrix[i][j] = matrix[n - j][i];
        matrix[n - j][i] = matrix[n - i][n - j];
        matrix[n - i][n - j] = temp;
      }
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }
