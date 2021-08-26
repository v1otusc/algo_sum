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
 * base 和 top 两种回溯
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
  int best_cost = INT_MAX;
  vector<int> base_costs;
  vector<int> top_costs;
  int target;

  // 实际上，目标价格和已有最优价格固定了剩下的更好的价格在下面的区间中
  // [target - abs(target - best_cost), target + abs(target - best_cost)]

  void dfs(bool have_base, int cur_cost, int topping_index) {
    if (have_base) {
      // 返回最接近 target 的甜点成本
      if (abs(cur_cost - target) < abs(best_cost - target)) {
        best_cost = cur_cost;
      }

      // 选择成本较低的一种
      if (abs(cur_cost - target) == abs(best_cost - target) &&
          cur_cost < best_cost) {
        best_cost = cur_cost;
      }

      // 完全超支，直接剪枝
      if (cur_cost > target + abs(best_cost - target)) {
        return;
      }
    }
    // 必须选择基底
    if (!have_base) {
      have_base = true;
      for (int i = 0; i < base_costs.size(); ++i) {
        cur_cost += base_costs[i];
        dfs(have_base, cur_cost, topping_index);
        cur_cost -= base_costs[i];
      }
    } else {
      // 可以添加一种或多种配料
      for (int i = topping_index; i < top_costs.size(); ++i) {
        // 加一份
        cur_cost += top_costs[i];
        dfs(have_base, cur_cost, i + 1);
        cur_cost -= top_costs[i];

        // 加两份
        cur_cost += top_costs[i] * 2;
        dfs(have_base, cur_cost, i + 1);
        cur_cost -= top_costs[i] * 2;
      }
    }
  }

 public:
  int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts,
                  int target) {
    this->base_costs = baseCosts;
    this->top_costs = toppingCosts;
    this->target = target;

    bool havebase = false;
    dfs(havebase, 0, 0);
    return best_cost;
  }
};

int main(int argc, char const* argv[]) { return 0; }
