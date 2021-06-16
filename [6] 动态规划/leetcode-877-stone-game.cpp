/*
 * @Description:
 *
 * 亚历克斯和李用几堆石子在做游戏。偶数堆 石子排成一行，每堆都有正整数颗石子
 * piles[i]
 *
 * 游戏以谁手中的石子最多来决出胜负。石子的总数是奇数，所以没有平局。
 *
 * 亚历克斯和李轮流进行，亚历克斯先开始。
 * 每回合，玩家从行的开始 或 结束处取走整堆石头。
 * 这种情况一直持续到没有更多的石子堆为止，此时手中石子最多的玩家获胜。
 *
 * 假设压力克斯和李都发挥出最佳水平，当亚力克斯赢得比赛时返回 true
 * 当李赢得比赛时返回 false
 *
 * @输入示例：
 *
 * [5,3,4,5]
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * 亚历克斯先开始，只能拿前 5 颗或后 5 颗石子 。
 * 假设他取了前 5 颗，这一行就变成了 [3,4,5] 。
 * 如果李拿走前 3 颗，那么剩下的是 [4,5]，亚历克斯拿走后 5 颗赢得 10 分。
 * 如果李拿走后 5 颗，那么剩下的是 [3,4]，亚历克斯拿走后 4 颗赢得 9 分。
 * 这表明，取前 5 颗石子对亚历克斯来说是一个胜利的举动，所以返回 true 。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 定义二维数组 dp，其行数和列数都等于石子的堆数，dp[i][j]
 * 表示石子堆为下标 i 到下标 j
 * 时，当前玩家与另一个玩家的石子数量之差的 最大值，注意当前玩家不一定是先手玩家
 *
 * 这个 dp 的设置和状态转移方程都很巧妙，注意当前玩家是一直在变的！
 *
 * 当 i=j 时，只剩下一堆石子，当前玩家只能取走这堆石子，因此对于所有
 * 0≤i<nums.length，都有 dp[i][i]=piles[i]
 *
 * 当 i<j 时，当前玩家可以选择取走 piles[i] 或
 * piles[j]，然后轮到另一个玩家在剩下的石子堆中取走石子。在两种方案中，当前玩家会选择最优的方案，使得自己的石子数量最大化。
 * 因此可以得到如下状态转移方程
 *
 * dp[i][j]=max(piles[i]−dp[i+1][j],piles[j]−dp[i][j−1])
 *
 * 最后判断 dp[0][piles.length−1] 的值，如果大于 0
 * 先手玩家赢得比赛
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool stoneGame(vector<int>& piles) {
    int n = piles.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
      dp[i][i] = piles[i];
    }
    // j >= i
    for (int i = n - 2; i >= 0; --i) {
      for (int j = i + 1; j < n; ++j) {
        dp[i][j] = max(piles[i] - dp[i + 1][j], piles[j] - dp[i][j - 1]);
      }
    }

    return dp[0][n - 1] > 0;
  }
};

int main(int argc, char const* argv[]) { return 0; }
