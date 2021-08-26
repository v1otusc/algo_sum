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

int rand7() { return rand() % 7 + 1; }

class Solution {
 public:
  int rand10() {
    while (true) {
      // 等概率生成 1 - 49
      int nums = (rand7() - 1) * 7 + rand7();
      if (nums <= 40) return nums % 10 + 1;
    }
  }
};

int main(int argc, char const* argv[]) { return 0; }
