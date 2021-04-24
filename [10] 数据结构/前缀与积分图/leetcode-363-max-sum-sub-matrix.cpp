/*
 * @Description:
 *
 * 给你一个 m x n 的矩阵 matrix 和一个整数 k
 * ，找出并返回矩阵内部矩形区域的不超过 k 的最大数值和。
 *
 * 题目数据保证总会存在一个数值和不超过 k 的矩形区域
 *
 * @输入示例：
 *
 * matrix = [[1, 0, 1], [0, -2, 3]], k = 2
 *
 * @输出实例：
 *
 * 2
 *
 * @输入输出说明：
 *
 * 矩形区域是[[0, 1], [-2, 3]] 的数值和为 2
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 看过 b 站上 acwing 的视频之后总结：
 *
 * 固定住行的上下边界和列的右边界（这个时候已经是三层for循环了）
 *
 * 然后移动矩形的左边界(计算前缀和)，利用 set 的
 * lower_bound()(即是平衡树的二分查找，时间复杂度 logn)
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
    int ans = INT_MIN;
    int m = matrix.size();
    int n = matrix[0].size();
    // 枚举上边界
    for (int i = 0; i < m; ++i) {
      vector<int> sum(n);
      // 枚举下边界
      for (int j = i; j < m; ++j) {
        for (int c = 0; c < n; ++c) {
          // 用来计算每一列之和
          sum[c] += matrix[j][c];
        }
        set<int> sumSet{0};
        // 储存前缀和
        int s = 0;
        for (int v : sum) {
          s += v;
          auto left = sumSet.lower_bound(s - k);
          if (left != sumSet.end()) {
            ans = max(ans, s - *left);
          }
          sumSet.insert(s);
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
