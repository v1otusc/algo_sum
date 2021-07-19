/*
 * @Description:
 *
 * 最小覆盖子串
 *
 * 给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。如果 s
 * 中不存在涵盖 t 所有字符的子串，则返回空字符串 ""。注意：如果 s
 * 中存在这样的子串，我们保证它是唯一的答案。同时要求时间复杂度不超过 O(n)。
 *
 * @输入示例：
 *
 *  S = "ADOBECODEBANC", T = "ABC"
 *
 * @输出实例：
 *
 *  "BANC"
 *
 * @输入输出说明：
 *
 * 输入是两个字符串 S 和 T,输出是一个 S 字符串的子串。
 *
 * @限制条件：
 *
 * 1 <= s.length, t.length <= 10^5
 *
 * @题目思路：
 *
 * 使用滑动窗口求解：
 *
 * 即两个指针 l 和 r 都是从最左端向最右端移动，且 l 的位置一定在 r 的左边或重合
 * 注意本题虽然在 for 循环里出现了一个 while 循环,但是因为 while 循环负责移动 l
 * 指针,且 l 只会从左到右移动一次,因此总时间复杂度仍然是 O(n)。
 * 使用了长度为 128 的数组来映射字符，也可以用哈希表代替，其中 chars
 * 表示目前每个字符缺失的数量，flags 表示每个字符是否在 T 中存在。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  string minWindow(string S, string T) {
    unordered_map<char, int> need, window;
    // 初始化 need 需要的字符及其个数
    for (auto c : T) need[c]++;

    // left right 是左闭右开的
    int left = 0, right = 0, valid = 0;

    // 记录最小覆盖子串的起始索引及长度
    int start = 0, len = INT_MAX;
    while (right < S.size()) {
      // 右移窗口
      char c = S[right];
      right++;

      // 进行窗口中的一系列更新
      if (need.count(c)) {
        window[c]++;
        // 某个字符已经满足条件了
        if (window[c] == need[c]) {
          valid++;
        }
      }

      // 判断是否可以左移窗口
      while (valid == need.size()) {
        // 更新最小覆盖子串
        if (right - left < len) {
          start = left;
          len = right - left;
        }
        // 左移窗口
        char d = S[left];
        left++;
        if (need.count(d)) {
          // 某个字符不满足个数要求了
          if (window[d] == need[d]) {
            valid--;
          }
          window[d]--;
        }
      }
    }
    return len == INT_MAX ? "" : S.substr(start, len);
  }
};

int main(int argc, char const* argv[]) {
  string S = "ADOBECODEBANC";
  string T = "ABC";
  Solution s;
  cout << s.minWindow(S, T) << endl;
  return 0;
}
