/*
 * @Description:
 *
 * 给定一个未排序的整数数组，求最长的递增子序列
 *
 按照 leetcode
 的习惯，子序列(subsequence)不必连续,子数组(subarray)或子字符串(substring)
 必须连续
 *
 * @输入示例：
 *
 * [10,9,2,5,3,7,101,18]
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * 在这个样例中，最长递增子序列是 [2, 3, 7, 18]
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 对于子序列问题,第一种(第二种为题目 1143)动态规划方法是,定义一个 dp 数组,其中
 dp[i] 表示以 i
 结尾的子序列的性质。在处理好每个位置后,统计一遍各个位置的结果即可得到题目要求的结果。

 在本题中，dp[i] 可以表示以 i 结尾的，最长子序列长度，对于每一个位置
 i，如果其之前的某一个 位置 j 所对应的数字小于位置 i
 所对应的数字,则我们可以获得一个以 i 结尾的，长度为 dp[j] + 1
 但是为了遍历所有情况，需要 i 和 j 进行两层循环，时间复杂度为 O(n^2)

 本题目还可以使用二分查找讲时间复杂度降到 O(nlogn)，首先定义一个 dp 数组，其中
 dp[k] 存储长度为 k+1 的最长递增子序列的最后一个数字。遍历每一个位置 i，如果其
 大于 dp 数组中的所有数字的值，那么我们把它放在 dp
 数组尾部,表示最长递增子序列长度加 1，如果我们发现这个数字在 dp 数组中比数字 a
 大、比数字 b 小,则我们用此数字替代 b,使得之后构成递增序列的可能性更大--贪心的思想
 以这种方式维护的 dp 数组永远是递增的，因此可以用二分查找加速搜索。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    if (n <= 0) {
      return n;
    }
    vector<int> dp;
    dp.push_back(nums[0]);
    for (int i = 1; i < n; ++i) {
      if (dp.back() < nums[i]) {
        dp.push_back(nums[i]);
      } else {
        auto itr = lower_bound(dp.begin(), dp.end(), nums[i]);
        *itr = nums[i];
      }
    }
    return dp.size();
  }
};

int main(int argc, char const* argv[]) { return 0; }