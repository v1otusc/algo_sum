/*
 * @Description:
 *
 * 给定一段时间内每天的，已知你只可以买卖一次，求最大的收益
 *
 * @输入示例：
 *
 * [7, 1, 5, 3, 6, 4]
 *
 * @输出实例：
 *
 * 5
 *
 * @输入输出说明：
 *
 * 在这个样例中,最大的利润为在第二天价格为 1 时买入,在第五天价格为 6 时卖出。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 我们可以遍历一遍数组,在每一个位置 i 时,记录 i 位置之前所有价格中的最低价格,然后
 将**当前的价格**作为售出价格,查看当前收益是不是最大收益即可。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int maxProfit(vector<int>& prices) {
    int sell = 0;
    int buy = INT_MAX;
    for (size_t i = 0; i < prices.size(); i++) {
      buy = min(buy, prices[i]);
      sell = max(sell, prices[i] - buy);
    }
    return sell;
  }
};

int main(int argc, char const* argv[]) { return 0; }