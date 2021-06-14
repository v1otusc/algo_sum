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
 * NULL
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 二分查找
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

/**
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			         1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

int guess(int num);

class Solution {
 public:
  int guessNumber(int n) {
    // 从 1-n 中选择数字
    int left = 1;
    int right = n;
    int mid = left + (right - left) / 2;
    while (left < right) {
      if (guess(mid) == 0)
        break;
      else if (guess(mid) == -1) {
        right = mid - 1;
      } else {
        left = mid + 1;
      }
      mid = left + (right - left) / 2;
    }
    return mid;
  }
};

int main(int argc, char const* argv[]) { return 0; }
