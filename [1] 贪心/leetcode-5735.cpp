/*
 * @Description:
 *
 * 商店中新到 n 支雪糕，用长度为 n 的数组 costs 表示雪糕的定价，其中 costs[i]
 * 表示第 i 支雪糕的现金价格。Tony 一共有 coins
 * 现金可以用于消费，他想要买尽可能多的雪糕。
 *
 * 给你价格数组 costs 和现金量 coins ，请你计算并返回 Tony 用 coins
 * 现金能够买到的雪糕的最大数量 。
 *
 * @输入示例：
 *
 * costs = [1,3,2,4,1], coins = 7
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * Tony 可以买下标为 0、1、2、4 的雪糕，总价为 1 + 3 + 2 + 1 = 7
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 贪心
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int maxIceCream(vector<int>& costs, int coins) {
    int res = 0;
    sort(costs.begin(), costs.end());
    for (int i = 0; i < costs.size(); ++i) {
      if (coins >= costs[i]) {
        res++;
        coins -= costs[i];
      } else {
        break;
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
