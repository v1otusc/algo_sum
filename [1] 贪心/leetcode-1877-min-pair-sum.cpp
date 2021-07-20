/*
 * @Description:
 *
 * 一个数对 (a,b) 的 数对和 等于 a + b 。最大数对和 是一个数对数组中最大的
 * 数对和 。比方说，如果我们有数对 (1,5) ，(2,3) 和 (4,4)，最大数对和 为
 * max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8 。
 *
 * 给一个长度为偶数 n 的数组，请你将 nums 中的元素分成 n / 2 个数对，使得：
 * - nums 中每个元素恰好在一个数对中
 * - 最大数对和的值最小
 *
 * @输入示例：
 *
 * nums = [3,5,2,3]
 *
 * @输出实例：
 *
 * 7
 *
 * @输入输出说明：
 *
 * 数组中的元素可以分为数对(3,3)和(5,2)
 * 最大数对和为max(3+3,5+2) = max(6,7)=7
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 贪心+找规律
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int minPairSum(vector<int>& nums) {
    int left = 0;
    int right = nums.size() - 1;
    sort(nums.begin(), nums.end());
    
    int ret = INT_MIN;
    while (left < right) {
      int tmp = nums[left++] + nums[right--];
      ret = (ret > tmp) ? ret : tmp;
    }
    return ret;
  }
};

int main(int argc, char const* argv[]) { return 0; }
