/*
 * @Description:
 *
 给定一个含有 0 到 n
 整数的数组,每个整数只出现一次,求这个数组最多可以分割成多少个
 子数组,使得对每个子数组进行增序排序之后再连接起来，使得连接的结果
 和按升序排序后的原数组相同
 *
 * @输入示例：
 *
 * [1, 0, 2, 3, 4]
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 我们可以把它分成两块，例如 [1, 0], [2, 3, 4]。
 然而，分成 [1, 0], [2], [3], [4] 可以得到最多的块数。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 方法：从左往右遍历，同时记录当前的最大值，每当当前最大值等于数组位置时,我们可以多一次分割。
 为什么？
 如果当前最大值大于数组位置，说明右边一定有小于数组位置的数字，需要把它也加入待排序的子数组；
 又因为数组只包含不重复的0到n，所以当前最大值一定不会小于数组位置，待排序的子数组;又因为数组只包含不重复的
 0 到 n,所以 所以每当当前最大值等于数组位置时,假设为
 p,我们可以成功完成一次分割,并且其与上一次分割位置 q 之间的值一定是 q + 1 到 p
 的所有数字。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int maxChunksToSorted(vector<int>& arr) {
    int chunks = 0;
    int cur_max = 0;
    for (int i = 0; i < arr.size(); ++i) {
      cur_max = max(cur_max, arr[i]);
      if (cur_max == i) {
        chunks++;
      }
    }
    return chunks;
  }
};

int main(int argc, char const* argv[]) { return 0; }
