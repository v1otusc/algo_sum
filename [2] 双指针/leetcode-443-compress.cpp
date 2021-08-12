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

class Solution {
 public:
  int compress(vector<char>& chars) {
    int n = chars.size();
    // 下标 index 表示可以放置字符的位置
    int index = 0;
    // 用 i 遍历整个数组
    int i = 0;
    while (i < n) {
      if (i + 1 < n && chars[i] == chars[i + 1]) {
        int j = i + 1;
        while (j < n && chars[j] == chars[i]) j++;
        
        chars[index++] = chars[i];
        chars[index++] = *(to_string(j-i).c_str());
        i = j;
      } else {
        chars[index++] = chars[i++];
      }
    }
    return index;
  }
};

int main(int argc, char const* argv[]) { return 0; }
