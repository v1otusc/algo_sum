/*
 * @Description:
 *
 * 给你一个整数数组 nums 和两个整数 k 和 t 。请你判断是否存在两个不同下标 i 和
 * j，使得 abs(nums[i] - nums[j]) <= t ，同时又满足 abs(i - j) <= k 。
 *
 * @输入示例：
 *
 * nums = [1, 2, ,3, 1]
 * k = 3
 * t = 0
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 * i = 0 j = 3 时满足条件
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用滑动窗口 + 有序的 set
 * 对于序列中每一个元素 x 左侧的至多 k 个元素，如果这 k
 * 个元素中存在一个元素落在区间 [x−t,x+t] 中，我们 就找到了一对符合条件的元素
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

// 超出时间限制的暴力写法
/*class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    // cout << n << endl;
    multimap<long long, pair<long, long>> diff_nums;
    for (int i = 0; i < n - 1; ++i) {
      for (int j = i + 1; j < n; ++j) {
        diff_nums.insert(make_pair(abs((long long)nums[j] - (long long)nums[i]),
make_pair(i, j)));
        // cout << "inserted" << endl;
      }
    }
    // sort(diff_nums.begin(), diff_nums.end());
    for (auto dn : diff_nums) {
      if ((abs(dn.first) <= t) &&
          (abs(dn.second.first - dn.second.second) <= k)) {
        return true;
      }
    }
    return false;
  }
};*/

// 使用滑动窗口的写法
class Solution {
 public:
  bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    int n = nums.size();
    set<int> rec;
    for (int i = 0; i < n; ++i) {
      // 找到大于等于 nums[i] - t, 为了防止越界
      auto iter = rec.lower_bound(max(nums[i], INT_MIN + t) - t);
      // 看看为了防止越界是怎么写的
      if (iter != rec.end() && *iter <= min(nums[i], INT_MAX - t) + t) {
        return true;
      }
      rec.insert(nums[i]);
      if(i >= k) {
        rec.erase(nums[i-k]);
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{1, 2, 3, 1};
  Solution s;
  if (s.containsNearbyAlmostDuplicate(nums, 3, 0)) {
    cout << "true" << endl;
  } else {
    cout << "false" << endl;
  }

  return 0;
}
