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
 * 逆推
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool reachingPoints(int sx, int sy, int tx, int ty) {
    //因为sx, sy, tx, ty 是范围在 [1, 10^9] 的整数，逆推不能出界
    while (tx > 0 && ty > 0) {
      if (sx == tx && sy == ty) {  //判断是否到达了起始值
        return true;
      }
      // 每次逆推只能有tx、ty中较大值减去较小值
      // 此时只能有tx减去ty
      // 每次多减几个，快速逼急
      if (tx > ty) {
        // tx -= ty;
        tx -= max(1, (tx - sx) / ty) * ty;
      } else {
        //此时只能有ty减去tx
        ty -= max(1, (ty - sy) / ty) * tx;
      }
    }
    return false;
  }
};

int main(int argc, char const* argv[]) { return 0; }
