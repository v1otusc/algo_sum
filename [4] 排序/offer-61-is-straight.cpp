/*
 * @Description:
 *
 *
 * 从扑克牌中随机抽5张牌，判断是不是一个顺子，即这5张牌是不是连续的。2～10为数字本身，A为1，J为11，Q为12，K为13，而大、小王为
 * 0 ，可以看成任意数字。A 不能视为 14。
 *
 * @输入示例：
 *
 * [1,2,3,4,5]
 * [0,0,1,2,5]
 *
 * @输出实例：
 *
 * True
 * True
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
  int count0(vector<int>& nums) {
    int count_0 = 0;
    for (auto& i : nums) {
      if (0 == i) {
        count_0++;
      } else {
        // 剪枝一下
        break;
      }
    }
    return count_0;
  }

  bool isStraight(vector<int>& nums) {
    sort(nums.begin(), nums.end());
    int count_0 = count0(nums);
    // 接着遍历 0 之后的数字
    int i = count_0;
    while (i + 1 < nums.size()) {
      if (nums[i + 1] == nums[i] + 1)
        i++;
      else {
        if (--count_0 < 0) return false;
        // 用完一张的效果，将当前的数加一，相当于万能牌，但是i不加1！
        nums[i] += 1;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) {
  vector<int> nums = {0, 0, 1, 2, 5};
  Solution s;
  if (s.isStraight(nums)) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }
  return 0;
}
