/*
 * @Description:
 *
 * 题目将给出我们一个数组nums与一个数字k
 * 我们的目的是从nums中选择出一些元素，使他们多次自增，成为数组中的另一个数x
 * 在最多进行k次自增后，要满足一个条件，就是x在数组中出现的次数最多
 * 也就是通过增大部分小于x的数的大小，使他们变成x
 *
 * @输入示例：
 *
 * nums = [1,2,4], k = 5
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 对第一个元素执行 3 次递增操作，对第二个元素执 2 次递增操作，此时 nums =
 * [4,4,4]。 4 是数组中最高频元素，频数是 3
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 滑动窗口
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int maxFrequency(vector<int>& nums, int k) {
    sort(nums.begin(), nums.end());
    int left = 0, right = 0;
    long long window = 0;
    int res = 0;
    while (right < nums.size()) {
      int max_ = nums[right];
      int count = right - left + 1;
      // 窗口中所有值之和(所有值均为最大)
      window += nums[right];
      right++;
      // 如果无法维持，则收缩窗口
      while (count > 0 && left < nums.size() && max_ * count - window > k) {
        window -= nums[left];
        left++;
        count--;
      }
      res = max(res, right - left);
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
