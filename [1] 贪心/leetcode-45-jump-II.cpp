/*
 * @Description:
 *
 * 给定一个非负整数数组，最初位于数组的第一个位置
 * 数组中的每个元素代表在该位置可以跳跃的最大长度
 * 目标是使用最少的跳跃次数达到数组的最后一个位置
 *
 * @输入示例：
 *
 * [2, 3, 1, 1, 4]
 *
 * @输出实例：
 *
 * 2
 *
 * @输入输出说明：
 *
 * 跳到最后一个位置的最小跳跃数是 2。
 * 从下标为 0 跳到下标为 1 的位置，跳 1 步，然后跳 3 步到达数组的最后一个位置。
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 贪心算法 反向开始查找距离自己最远的跳跃点
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int jump(vector<int>& nums) {
    int position = nums.size() - 1;
    int steps = 0;
    while (position > 0) {
      // 查找距自己最远的跳跃点
      for (int i = 0; i < position; ++i) {
        if (i + nums[i] >= position) {
          position = i;
          steps++;
          break;
        }
      }
    }
    return steps;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums{2,3,1,1,4};
  Solution s;
  cout << s.jump(nums) << endl;
  return 0;
}
