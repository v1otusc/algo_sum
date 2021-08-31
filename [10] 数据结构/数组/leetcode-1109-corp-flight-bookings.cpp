/*
 * @Description:
 *
 * 区间求和解法
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
 * 差分数组的性质是，当我们希望对原数组的某一个区间 [l, r] 施加一个增量时
 * 差分数组 d[l] 增加 inc，d[r+1] 减少 inc
 * 对于区间的修改就变为了对于两个位置的修改。并且这种修改是可以叠加的
 * 即当我们多次对原数组的不同区间施加不同的增量，我们只要按规则修改差分数组即可。
 *
 * 本题中计算完差分数组之后，需要求出差分数组的前缀和
 * 
 * 实际上差分和前缀互为逆过程咯
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
    // 注意差分数组的长度
    vector<int> nums(n + 1);
    // 首先构造差分数组
    for (auto& booking : bookings) {
      nums[booking[0] - 1] += booking[2];
      nums[booking[1]] -= booking[2];
    }

    // 然后求前缀和
    vector<int> ans(n);
    ans[0] = nums[0];
    for (int i = 1; i < n; ++i) {
      ans[i] += ans[i - 1] + nums[i];
    }

    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
