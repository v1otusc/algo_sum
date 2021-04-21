/*
 * @Description:
 *
 * 给定一个字符串，找出其中不含有重复字符的连续最长子串的长度
 *
 * @输入示例：
 *
 * s = "pwwkew"
 *
 * @输出实例：
 *
 * 3
 *
 * @输入输出说明：
 *
 * 最长的连续子串为 wke
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用滑动窗口+双指针
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

struct ListNode {
  int val;
  ListNode* next;
  ListNode(int x) : val(x), next(nullptr) {}
  ListNode(int x, ListNode* next) : val(x), next(next) {}
};

class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    int max_len = 0;
    int n = s.length();
    for (int i = 0; i < n; ++i) {
    }
    return max_len;
  }
};

int main(int argc, char const* argv[]) { return 0; }
