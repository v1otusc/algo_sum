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
  static string minWindow(string S, string T) {
    // 为什么要使用长度为 128 的数组来映射字符？ 因为 ASCII 码表共有 128
    // 个字符。
    // 表示 S 中每个字符缺少的数量
    vector<int> chars(128, 0);
    // 表示每个字符是否在 T 中存在
    vector<bool> flag(128, false);

    // 先统计 T 中的字符情况
    for (size_t i = 0; i < T.size(); i++) {
      // 这里实际上发生了一个隐式转换，即将字符转换为其对应的 ASCII 码表中的位置
      // A-Z 65-90 a-z 97-122
      flag[T[i]] = true;
      ++chars[T[i]];
    }
    int cnt = 0;
    int l = 0;
    int min_l = 0;
    // 故意多加个 1，这样就能方便最后返回空字符串
    int min_Size = S.size() + 1;
    // 移动滑动窗口，不断更改统计数据
    for (size_t r = 0; r < S.size(); r++) {
      if (flag[S[r]]) {
        if (--chars[S[r]] >= 0) {
          ++cnt;
        }

        // 若目前滑动窗口已包含 T 中全部字符
        // 则尝试将 l 右移，在不影响结果的情况下获得最短字符串
        while (cnt == T.size()) {
          if (r - l + 1 < min_Size) {
            min_l = l;
            min_Size = r - l + 1;
          }
          if (flag[S[l]] && ++chars[S[l]] > 0) {
            --cnt;
          }
          ++l;
        }
      }
    }
    // substr 中的第二个参数为 substring 的长度
    return min_Size > S.size() ? "" : S.substr(min_l, min_Size);
  }
};

int main(int argc, char const* argv[]) {
  string S = "ADOBECODEBANC";
  string T = "ABC";
  cout << Solution::minWindow(S, T) << endl;
  return 0;
}
