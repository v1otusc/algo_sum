/*
 * @Description:
 *
 给定多个字符串，求其中任意两个字母串的长度乘积的最大值，且这两个字母串不能含有相同字母
 *
 * @输入示例：
 *
 * ["a", "ab", "abc", "d", "cd", "bcd", "abcd"]
 *
 * @输出实例：
 *
 * 4
 *
 * @输入输出说明：
 *
 * 在这个选择中，一种最优的选择是 "ab" 和 "cd"
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 快速判断两个字母串是否含有重复数字的方法：
 * 为每个字母串建立一个长度为 26 的二进制数字、每个位置表示是否存在该字母
 * 如果两个字母串含有重复数字,那它们的二进制表示的按位与不为
 0。同时，建立一个哈希表来存储字母串(在数组的位置)到二进制数字的映射关系，方便查找调用
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  int maxProduct(vector<string>& words) {
    unordered_map<int, int> hash;
    int ans = 0;
    for (const string& word : words) {
      int mask = 0;
      int size = word.size();
      for (const char& c : word) {
        // 建立一个长度为 26 的二进制数字、每个位置表示是否存在该字母
        mask |= 1 << (c - 'a');
      }
      // 为什么要用 max, 因为有可能同时存在 aaab 和 ab 这种情况
      // 应该使用前者才能使得乘积最大
      hash[mask] = max(hash[mask], size);
      for (const auto& h : hash) {
        int h_mask = h.first;
        int h_len = h.second;
        // 按位与为 0，说明没有重复数字
        if (!(mask & h_mask)) {
          ans = max(ans, hash[mask] * h_len);
        }
      }
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
