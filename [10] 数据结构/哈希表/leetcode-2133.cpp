/*
 * @Description:
 *
 *  对一个大小为 n x n 的矩阵而言，如果其每一行和每一列都包含从 1 到 n 的 全部 整数（含 1 和 n），则认为该矩阵是一个 有效 矩阵。
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
 * 等价于每一行每一列都不重复， 
 *
 * @LastEditors: zzh
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool checkvalid(vector<vector<int>>& matrix) {
    int n = matrix.size();
    unordered_set<int> occr;
    for (size_t i = 0; i < n; ++i) {
      occr.clear();
      for (size_t j = 0; j < n; ++j) {
        if(occr.count(matrix[i][j])) {
          return false;
        }
        occr.insert(matrix[i][j]);
      }
    }
    
    for (size_t i = 0; i < n; ++i) {
      occr.clear();
      for (size_t j = 0; j < n; ++j) {
        if(occr.count(matrix[j][i])) {
          return false;
        }
        occr.insert(matrix[j][i]);
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
