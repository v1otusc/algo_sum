/*
 * @Description:
 *
 *
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
 * 在二维数组中进行二分
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
    // rows
    int m = matrix.size();
    // cols
    int n = matrix[0].size();
    int left = 0, right = m * n;
    while (left < right) {
      int mid = left + (right - left) / 2;
      // 二维数组中元素的表示方法
      int x = matrix[mid / n][mid % n];
      if (x == target) {
        return true;
      } else if (x < target) {
        left = mid + 1;
      } else {
        right = mid;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) { return 0; }
