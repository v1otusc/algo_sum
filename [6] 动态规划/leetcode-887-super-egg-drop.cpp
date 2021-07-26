/*
 * @Description:
 *
 * 给你 k 枚相同的鸡蛋，并可以使用一栋从第 1 层到第 n 层共有 n 层楼的建筑。
 * 已知存在楼层 f ，满足 0 <= f <= n ，任何从 高于 f 的楼层落下的鸡蛋都会碎，从
 * f 楼层或比它低的楼层落下的鸡蛋都不会破。
 * 每次操作，你可以取一枚没有碎的鸡蛋并把它从任一楼层 x 扔下
 * 如果鸡蛋碎了，你就不能再次使用它。如果某枚鸡蛋扔下后没有摔碎，则可以在之后的操作中
 * 重复使用这枚鸡蛋。
 * 请你计算并返回要确定 f 确切的值的最小操作次数是多少？
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
  // unorder_map 利用 std::hash 来计算 key, 但是 C++ 中没有给 pair 作 hash
  // 的函数
  map<pair<int, int>, int> ump;

 public:
  // 所剩鸡蛋的个数 —— 从第几层开始扔
  int dp(int k, int n) {
    if (k == 1) return n;
    if (n == 0) return 0;
    if (ump.find(make_pair(k, n)) != ump.end()) {
      return ump[make_pair(k, n)];
    }

    // 从第一层到第 n 层开始试
    int res = INT_MAX;

    // for (int i = 1; i < n + 1; ++i) {
    //  res = min(res, (max(dp(k, n - i), dp(k - 1, i - 1)) + 1));
    // }
    // 用二分来替代上述代码，依据是两个函数的曲线
    int low = 1;
    int high = n;
    while (low <= high) {
      int mid = low + (high - low) / 2;
      int broken = dp(k - 1, mid - 1);
      int unbroken = dp(k, n - mid);
      if (broken > unbroken) {
        high = mid - 1;
        res = min(res, broken + 1);
      } else {
        low = mid + 1;
        res = min(res, unbroken + 1);
      }
    }

    ump[make_pair(k, n)] = res;
    return res;
  }

  int superEggDrop(int k, int n) {
    int ans = dp(k, n);
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  Solution s;
  int ans = s.superEggDrop(2, 6);
  cout << ans << endl;
  return 0;
}
