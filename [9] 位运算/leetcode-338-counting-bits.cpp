/*
 * @Description:
 *
 * 给定一个非负整数 n，求从 0 到 n 的所有数字的二进制表达中，分别有多少个 1。
 *
 * @输入示例：
 *
 * 5
 *
 * @输出实例：
 *
 * [0,1,1,2,1,2]
 *
 * @输入输出说明：
 *
 输入是一个非负整数 n,输出是长度为 n + 1 的非负整数数组,每个位置 m 表示 m
 的二进制里有多少个 1。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 利用动态规划和位运算进行快速的求解
 * 定义一个数组 dp,其中 dp[i] 表示数字 i 的二进制含有 1 的个数
 * 对于第 i 个数字，如果它二进制的最后一位为 1，那么它含有 1 的个数则为
 * dp[i-1] + 1，如果它二进制的最后一位为 0，那么它含有 1 的个数和其右移结果相同
 * 即 dp[i>>1]（把最后一位社去）
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> countBits(int num) {
    vector<int> dp(num + 1, 0);
    for (int i = 1; i <= num; ++i) {
      dp[i] = (i & 1) ? dp[i - 1] + 1 : dp[i >> 1];
    }
    return dp;
  }
};

int main(int argc, char const* argv[]) { return 0; }