/*
 * @Description:
 *
 * 给定 n 个非负整数表示每个宽度为 1
 * 的柱子的高度图，计算按此排列的柱子，下雨之后能接多少雨水
 *
 * @输入示例：
 *
 * height = [0,1,0,2,1,0,1,3,2,1,2,1]
 *
 * @输出实例：
 *
 * 6
 *
 * @输入输出说明：
 *
 * 上面是由数组 [0,1,0,2,1,0,1,3,2,1,2,1] 表示的高度图，在这种情况下，可以接 6
 * 个单位的雨水（蓝色部分表示雨水）。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 本题可以抽象为：对 height 中的每个位置，分别找出其左右最高的柱子，记为
 * max_l 和 max_r，则每个位置的储水量为 min(max_l, max_r) - height[i]
 * 然后叠加各位置的储水量即为答案；
 *
 * 使用左右双指针，配合两个变量维护 max_l 和 max_r
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int trap(vector<int>& height) {
    int ans = 0;
    int left = 0, right = height.size() - 1;
    int leftMax = 0, rightMax = 0;
    while (left < right) {
      leftMax = max(leftMax, height[left]);
      rightMax = max(rightMax, height[right]);
      if (height[left] < height[right]) {
        ans += leftMax - height[left];
        ++left;
      } else {
        ans += rightMax - height[right];
        --right;
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
