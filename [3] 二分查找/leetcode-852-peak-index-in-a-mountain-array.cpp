/*
 * @Description:
 *
 * 符合下列属性的数组 arr 称为山脉数组
 * arr.length >= 3
 * 存在 i (0 < i < arr.length - 1) 使得
 * arr[0] < arr[1] < ... < arr[i-1] < arr[i]
 * arr[i] > arr[i+1] > ... > arr[arr.length - 1]
 *
 * 给一组由整数组成的山脉数组，返回山顶元素的下标
 *
 * @输入示例：
 *
 * arr = [0，10，5，2]
 *
 * @输出实例：
 *
 * 1
 *
 * @输入输出说明：
 *
 * NULL
 *
 * @限制条件：
 *
 * arr.length >= 3
 * 设计一个 O(logn) 的解决方案
 *
 * @题目思路：
 *
 * 用二分查找出元素的最大值
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int peakIndexInMountainArray(vector<int>& arr) {
    int n = arr.size();
    // 左闭右开的写法
    int l = 0;
    int r = n;
    // 左闭右闭的写法 int l = 0, r = n - 1
    int mid = l + (r - l) / 2;
    // int max = arr[mid];
    while (l < n) {
      if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) {
        return mid;
      } else if (arr[mid] < arr[mid - 1] && arr[mid] > arr[mid + 1]) {
        // 左闭右开的写法
        r = mid;
        // 左闭右闭的写法 r = mid - 1;
        // 此时 r 能取到
      } else {
        l = mid + 1;
      }
      mid = l + (r - l) / 2;
    }
    return mid;
  }
};

int main(int argc, char const* argv[]) { return 0; }