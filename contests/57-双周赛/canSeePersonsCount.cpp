/*
 * @Description:
 *
 *
 *
 * @输入示例：
 *
 *
 *
 * @输出实例：
 *
 *
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
  vector<int> canSeePersonsCount(vector<int>& heights) {
    vector<int> ans;
    for (int i = 0; i < heights.size(); ++i) {
      if (i == heights.size() - 1) {
        ans.push_back(0);
        break;
      }
      int i_res = 1;
      int maxh = heights[i + 1];
      for (int j = i + 2; j < heights.size(); ++j) {
        maxh = (heights[j - 1] > maxh) ? heights[j - 1] : maxh;
        if (min(heights[i], heights[j]) > maxh) {
          i_res++;
        } else {
          ans.push_back(i_res);
          break;
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
