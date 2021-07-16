/*
 * @Description:
 *
 * 你一个正整数数组 arr 。请你对 arr
 * 执行一些操作（也可以不进行任何操作），使得数组满足以下条件：

 * arr 中 第一个 元素必须为 1 。
 * 任意相邻两个元素的差的绝对值 小于等于 1 ，也就是说，对于任意的 1 <= i <
 * arr.length （数组下标从 0 开始），都满足 abs(arr[i] - arr[i - 1]) <=
 * 1。abs(x)
 * 为 x 的绝对值。
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
 * 数组中相邻两个元素，要么后者等于前者，要么后者等于前者加上 1。
 * 先将数组进行升序排序，随后对数组进行遍历，将 arr[i]
 * 更新为其自身与 arr[i−1]+1 中的较小值即可。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
    sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (size_t i = 1; i < arr.size(); ++i) {
      // arr[i] = (abs(arr[i] - arr[i - 1]) <= 1) ? arr[i] : arr[i] + 1;
      arr[i] = min(arr[i], arr[i - 1] + 1);
    }
    return arr[arr.size() - 1];
  }
};

int main(int argc, char const* argv[]) { return 0; }
