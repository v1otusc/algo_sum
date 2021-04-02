/*
 * @Description:
 *
 给定一个长度为 n 的数组,其中包含范围为 1 到 n
 的整数,有些整数重复了多次,有些整数 没有出现,求 1 到 n 中没有出现过的整数。
 *
 * @输入示例：
 *
 * [4,3,2,7,8,2,3,1]
 *
 * @输出实例：
 *
 * [5, 6]
 *
 * @输入输出说明：
 *
 输入是一个一维整数数组,输出也是一个一维整数数组,表示输入数组内没出现过的数字。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 接对原数组进行标记，把出现的数字在原数组出现的位置设为负数，最后仍为正数的位置
 即为没有出现的数。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> findDisappearedNumbers(vector<int>& nums) {
    vector<int> ans;
    for (const int& num : nums) {
      // 因为会变成负数，所以要加 abs
      int pos = abs(num) - 1;
      if (nums[pos] > 0) {
        nums[pos] = -nums[pos];
      }
    }
    for (int i = 0; i < nums.size(); ++i) {
      if (nums[i] > 0) {
        ans.push_back(i + 1);
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
