/*
 * @Description:
 *
 * 给定一个整数数组，求这个数组中可以组成的最长连续序列有多长
 *
 * @输入示例：
 *
 * [100, 4, 200, 1, 3, 2]
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * 在这个样例中,最长连续序列是 [1,2,3,4]。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 把所有数组放到一个哈希表，然后不断地从哈希表中任意取一个值，并删除掉其之前之后的所有连续数字
 * 然后更新目前的最长连续序列长度。重复这一过程，我们就可以找到所有的连续数字序列。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int longestConsecutive(vector<int>& nums) {
    unordered_set<int> hash;
    for (const int& num : nums) {
      hash.insert(num);
    }
    int ans = 0;
    while (!hash.empty()) {
      // 从哈希表中任意取一个值
      int cur = *(hash.begin());
      hash.erase(cur);
      int next = cur + 1;
      int prev = cur - 1;
      while (hash.count(next)) {
        // 先用再++
        hash.erase(next++);
      }
      while (hash.count(prev)) {
        hash.erase(prev--);
      }
      ans = max(ans, next - prev - 1);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
