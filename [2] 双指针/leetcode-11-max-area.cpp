/*
 * @Description:
 *
 * 给你 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai)
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 *
 * @输入示例：
 *
 * [1,8,6,2,5,4,8,3,7]
 *
 * @输出实例：
 *
 * 49
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
 * 双指针
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int maxArea(vector<int>& height) {
    int l = 0;
    int r = height.size() - 1;
    int max_area = 0;
    while (l < r) {
      int area = min(height[r], height[l]) * (r - l);
      max_area = max(area, max_area);
      if (height[r] < height[l]) {
        r--;
      } else {
        l++;
      }
    }
    return max_area;
  }
};

int main(int argc, char const* argv[]) { return 0; }
