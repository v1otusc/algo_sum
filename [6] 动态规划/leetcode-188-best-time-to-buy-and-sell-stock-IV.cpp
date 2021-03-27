/*
 * @Description:
 *
 给定一段时间内每天的股票价格，已知你只可以买卖 k
 次,且每次只能拥有一支股票,求最大的收益
 *
 * @输入示例：
 *
 * [3, 2, 6, 5, 0, 3]
 * k = 2
 *
 * @输出实例：
 *
 * 7
 *
 * @输入输出说明：
 *
 输入一个一维整数数组，表示每天的股票价格，以及一个整数，表示可以买卖的次数
 k，输入一个整数，表示最大的收益

 在这个样例中,最大的利润为在第二天价格为 2 时买入,在第三天价格为 6 时卖出;
 再在第五天价格为 0 的时买入，在第六天价格为 3 的时候卖出
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 分情况：
 如果 k 大约总天数,那么我们一旦发现可以赚钱就进行买卖。如果 k
 小于总天数,我们可以建立两个动态规划数组 buy 和 sell,对于每天的股票价格,buy[j]
 表示在第 j 次买入时的最大收益，sell[j] 表示在第 j 次卖出时的最大收益。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int maxProfit(int k, vector<int>& prices) {
    int days = prices.size();
    // 赚不到钱
    if (days < 2) {
      return 0;
    }
    if (k >= days) {
      return maxProfitUnlimited(prices);
    }
    // 已经是空间压缩后的做法
    vector<int> buy(k + 1, INT_MIN);
    vector<int> sell(k + 1, 0);

    for (int i = 0; i < days; ++i) {
      for (int j = 1; j <= k; ++j) {
        // 如果是第 i 天买入的，那么在第 i−1
        // 天时，我们手上不持有股票，对应状态
        // sell[j-1],并且需要扣除 prices[i] 的买入花费
        buy[j] = max(buy[j], sell[j - 1] - prices[i]);
        // 如果是第 i 天卖出的，那么在第 i-1 天时，手上持有股票
        // 对应状态 buy[j](已经买入了) 再加上收入费用
        sell[j] = max(sell[j], buy[j] + prices[i]);
      }
    }
    return sell[k];
  }

  // 当 k >= days 时，可以无限买入卖出
  static int maxProfitUnlimited(vector<int>& prices) {
    int maxProfitUnlimited = 0;
    for (int i = 1; i < prices.size(); ++i) {
      if (prices[i] > prices[i - 1]) {
        maxProfitUnlimited += prices[i] - prices[i - 1];
      }
    }
    return maxProfitUnlimited;
  }
};

int main(int argc, char const* argv[]) { return 0; }