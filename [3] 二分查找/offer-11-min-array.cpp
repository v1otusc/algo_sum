/*
 * @Description:
 *
 * 获取旋转数组中的最小值
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
  int minArray(vector<int>& numbers) {
    int low = 0, high = numbers.size() - 1;
    while (low < high) {
      int pivot = low + (high - low) / 2;
      if (numbers[pivot] < numbers[high]) {
        high = pivot;
      } else if (numbers[pivot] > numbers[high]) {
        low = pivot + 1;
      } else {
        // 这个时候就尴尬了，只能慢慢减去试了
        high--;
      }
    }
    // 此时 low = high;
    return numbers[low];
  }
};

int main(int argc, char const* argv[]) { return 0; }