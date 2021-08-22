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
  double probabilityOfHeads(vector<double>& prob, int target) {
    int n = prob.size();
    vector<vector<int>> dp(n+1, vector<int>(n+1, 0));
    
    
    return dp[n][target];
  }
};

int main(int argc, char const* argv[]) { return 0; }
