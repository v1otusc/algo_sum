/*
 * @Description:
 *
 * 给定一个非负数，求它的开方，向下取整
 *
 * @输入示例：
 *
 * 8
 *
 * @输出实例：
 *
 * 2
 *
 * @输入输出说明：
 *
 * 输入一个整数,输出一个整数。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 我们可以把这道题想象成,给定一个非负整数 a,求 f (x) = x^2 − a = 0
 * 的解。因为我们只考虑 x ≥ 0,所以 f (x) 在定义域上是单调递增的。考虑到 f (0) =
 * −a ≤ 0, f (a) = a^2 − a ≥ 0,可以对 [0, a] 区间使用二分法找到 f (x) = 0 的解。
 *
 * 注意，在以下的代码中，为了防止除以 0，把 a = 0 的情况单独考虑，然后对区间 [1,
 * a] 进行二分查找，并且使用了左闭右闭的写法。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/[3]二分查找/leetcode-69-sqrt(x).cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int mySqrt(int x) {
    // 首先考虑特殊情况，防止 x 除以 0 或者负数
    if (x <= 0) {
      return 0;
    }

    int l = 1, r = x, mid, ans;
    while (l <= r) {
      mid = l + (r - l) / 2;
      // 防止越界，用 long long
      if ((long long)mid * mid <= x) {
        ans = mid;
        l = mid + 1;
      } else {
        // 不能写 ans = mid;
        // 原因是，要向下取整；如果向上取整，if 不写 else 写；
        r = mid - 1;
      }
    }
    return ans;
  }
};

// 牛顿迭代法的写法
int mySqrt(int x) {
  long res = x;
  while (res * res > x) {
    res = (res + x / res) / 2;
  }
  return res;
}

int main(int argc, char const* argv[]) {
  int x = 8;
  cout << Solution::mySqrt(x) << endl;
  cout << mySqrt(x) << endl;
  return 0;
}