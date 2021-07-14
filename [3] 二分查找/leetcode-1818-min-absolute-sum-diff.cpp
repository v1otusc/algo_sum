/*
 * @Description:
 *
 * 给你两个正整数数组 nums1 和 nums2，数组的长度都是 n
 * 数组 nums1 和 nums2 的 绝对差值和 定义为所有 |nums1[i] - nums2[i]|（0 <= i <
 * n）的 总和（下标从 0 开始）。
 *
 * 你可以选用 nums1 中的任意一个元素来替换 nums1
 * 中的至多一个元素，以最小化绝对差值和
 *
 * 在替换数组 nums1 中最多一个元素 之后
 * ，返回最小绝对差值和。因为答案可能很大，所以需要对 10e9 + 7 取余 后返回。
 *
 * @输入示例：
 *
 * nums1 = [1, 7, 5]
 * nums2 = [2, 3, 5]
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 有两种可能的最优方案
 * - 将第二个元素替换为第一个元素
 * - 将第二个元素替换为第三个元素
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 目标函数找错了，会出现下面的错误：
 * [1,28,21]
 * [9,21,20]
 * 输出：16
 * 预期：9
 *
 * 单个二元组 {nums1[i], nums2[i]} 对答案的贡献为 ∣nums1[i]−nums2[i]|
 * 假设我们用元素 nums1[j] 替换了元素 nums1[i]，那么此时该二元组对答案的贡献为
 * ∣nums1[j]−nums2[i]∣ 改变前后的差值为：
 *
 * |nums1[i] - nums2[i]| - |nums1[j] - nums2[i]|
 *
 * 最大化该差值，这样可以使得答案尽可能小。
 *
 * 当 i 确定时，该式的前半部分的值即可确定，而后半部分的值取决于 j
 * 的选择。观察该式，我们只需要找到和 nums2[i]
 * 尽可能接近的 nums1[j] 即可。
 *
 * 为了优化时间复杂度，这一过程采用二分查找的方法
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static constexpr int mod = 1'000'000'007;

 public:
  int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
    vector<int> rec(nums1);
    sort(rec.begin(), rec.end());
    // 所有的差值和
    int sum = 0;
    // 要最大化的目标值
    int target = 0;
    int n = nums1.size();
    for (size_t i = 0; i < n; ++i) {
      int diff = abs(nums1[i] - nums2[i]);
      sum = (sum + diff) % mod;
      int j = lower_bound(rec.begin(), rec.end(), nums2[i]) - rec.begin();

      // 要求的 nums1[j] 既有可能大于 nums2[i] 也有可能小于 nums2[i]

      if (j < n) {
        target = max(target, diff - (rec[j] - nums2[i]));
      }
      if (j > 0) {
        target = max(target, diff - (nums2[i] - rec[j - 1]));
      }
    }
    return (sum - target + mod) % mod;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums1{1, 7, 5};
  vector<int> nums2{2, 3, 5};
  Solution s;
  cout << s.minAbsoluteSumDiff(nums1, nums2) << endl;
  return 0;
}
