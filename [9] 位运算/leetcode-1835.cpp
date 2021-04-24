/*
 * @Description:
 *
 *
 *
 * @输入示例：
 *
 * arr1 = [1, 2, 3], arr2 = [6, 5]
 *
 * @输出实例：
 *
 * NULL
 *
 * @输入输出说明：
 *
 * 列表 = [1 AND 6, 1 AND 5, 2 AND 6, 2 AND 5, 3 AND 6, 3 AND 5] = [0,1,2,0,2,1]
 * 异或和 = 0 XOR 1 XOR 2 XOR 0 XOR 2 XOR 1 = 0
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 详见注释
 * 视频讲解
 * https://www.youtube.com/watch?v=d0cbmU9v-Pc
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int getXORSum(vector<int>& arr1, vector<int>& arr2) {
    // bits 表示对于每一个数，对应的每一个 pos 位为 1 的个数之和；
    // int 四个字节，32 位
    vector<int> bit(32, 0);
    for (int a : arr2) {
      int pos = 0;
      while (a > 0) {
        if (a & 1) {
          bit[pos]++;
        }
        a = a >> 1;
        pos++;
      }
    }

    int res = 0;

    for (int a : arr1) {
      int pos = 0;
      int tmp = 0;
      while (a > 0) {
        // arr1 的此位为 1，才有可能为 1
        if (a & 1) {
          // 如果此位为 1 之和为奇数，才有可能为1
          if (bit[pos] % 2 == 1) {
            tmp |= (1 << pos);
          }
        }
        a = a >> 1;
        pos++;
      }
      res ^= tmp;
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
