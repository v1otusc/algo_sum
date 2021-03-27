/*
 * @Description:
 *
 给定一段时间内每天的股票价格，已知每次卖出后必须冷却一天，且每次只能拥有一只股票
 求最大收益
 *
 * @输入示例：
 *
 * [1, 2, 3, 0, 2]
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 输入一个一维整数数组,表示每天的股票价格;输出一个整数,表示最大的收益。
 * 在这个样例中,最大的利润获取操作是买入、卖出、冷却、买入、卖出。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 我们可以使用状态机来解决这类复杂的状态转移问题,通过建立多个状态以及它们的转移方
 式,我们可以很容易地推导出各个状态的转移方程。如图所示,我们可以建立四个状态来表示带
 有冷却的股票交易,以及它们的之间的转移方式。
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
    
  }
};

int main(int argc, char const* argv[]) { return 0; }