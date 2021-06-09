/*
 * @Description:
 *
 * 给定一个字符串，找出其中不含重复字符的 最长子串 的长度
 *
 * @输入示例：
 *
 * s = "abcabcbb"
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 因为无重复字符的最长子串是 "abc"，所以其长度为 3
 *
 * @限制条件：
 *
 * 注意，你的答案必须是 子串 的长度，子序列可以不连续，但是子串必须连续
 *
 * @题目思路：
 *
 * 使用滑动窗口
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    // 需要一个数据结构来判断是否有重复的重复的字符串：unordered_set
    unordered_set<int> c_set;
    // 右指针，初始化为下标 -1, 更加巧妙
    int rp = -1;
    int ans = 0;
    int s_size = s.size();
    // c_set.insert(s[0]);
    // 枚举左指针的位置，初始值隐示地表示为 -1
    for (int i = 0; i < s_size; ++i) {
      if (i != 0) {
        // 左指针向右移动，移除一个字符
        c_set.erase(s[i - 1]);
      }
      while (rp + 1 < s_size && c_set.count(s[rp + 1]) == 0) {
        c_set.insert(s[rp++]);
        // rp++;
      }
      ans = max(ans, rp - i + 1);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string s = "abcbc";
  Solution ans;
  cout << ans.lengthOfLongestSubstring(s) << endl;
  return 0;
}
