/*
 * @Description:
 * 
 * 华为笔试 HW-16
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
#include <iostream>
#include <vector>

using namespace std;

int main(int argc, char** argv) {
  int N, m;
  // 总钱数，希望购买物品的个数
  cin >> N >> m;
  // 物品价格
  vector<vector<int>> prices(61, vector<int>(3, 0));
  // 重要程度，包含主件和附件
  vector<vector<int>> priority(61, vector<int>(3, 0));
  for (int i = 1; i <= m; ++i) {
    int v, p, q;
    // 其中 v 表示该物品的价格（v<10000 ）， p 表示该物品的重要度（1 ~ 5）， q
    // 表示该物品是主件还是附件。如果 q=0 ，表示该物品为主件，如果 q>0
    //，表示该物品为附件， q是所属主件的编号
    cin >> v >> p >> q;
    // 存入形式
    p *= v;
    // 如果是主件
    if (q == 0) {
      prices[i][0] = v;
      priority[i][0] = p;
    } else {
      // 附件 1 还没有
      if (prices[q][1] == 0) {
        prices[q][1] = v;
        priority[q][1] = p;
      } else {
        // 附件 1 已经有了， 放附件 2
        prices[q][2] = v;
        priority[q][2] = p;
      }
    }
  }
  // 在不超过 N 元的情况下，能获得的价格总数
  vector<vector<int>> dp(m + 1, vector<int>(N + 1, 0));
  for (int i = 1; i < m + 1; ++i) {
    for (int j = 1; j < N + 1; ++j) {
      // 主件和附件的价格和优先程度
      int a = prices[i][0], b = priority[i][0];
      int c = prices[i][1], d = priority[i][1];
      int e = prices[i][2], f = priority[i][2];
      // 注意下面优先级的使用
      // 这里我感觉逻辑是错的。。。
      dp[i][j] =
          j >= a ? max(dp[i - 1][j - a] + b, dp[i - 1][j]) : dp[i - 1][j];
      dp[i][j] =
          j >= (a + c) ? max(dp[i - 1][j - a - c] + b + d, dp[i][j]) : dp[i][j];
      dp[i][j] =
          j >= (a + e) ? max(dp[i - 1][j - a - e] + b + f, dp[i][j]) : dp[i][j];
      dp[i][j] = j >= (a + c + e)
                     ? max(dp[i - 1][j - a - c - e] + b + d + f, dp[i][j])
                     : dp[i][j];
    }
  }
  cout << dp[m][N] << endl;
}