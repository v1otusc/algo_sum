/*
 * @Description:
 *
 判断两个字符串是否同构。同构的定义是,可以通过把一个字符串的某些相同的字符转换成
 另一些相同的字符,使得两个字符串相同,且两种不同的字符不能够被转换成同一种字符。
 *
 * @输入示例：
 *
 * s = "paper"
 * t = "title"
 *
 * @输出实例：
 *
 * true
 *
 * @输入输出说明：
 *
 在这个样例中,通过把 s 中的 p、a、e、r 字符转换成 t、i、l、e
 字符,可以使得两个字符串相同,
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 我们可以将问题转化一下:记录两个字符串每个位置的字符第一次出现的位置,如果两个字
 符串中相同位置的字符与它们第一次出现的位置一样,那么这两个字符串同构。举例来说,对于
 “paper”和“title”
 ,假设我们现在遍历到第三个字符“p”和“t”
 ,发现它们第一次出现的位置都
 在第一个字符,则说明目前位置满足同构。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool isIsomorphic(string s, string t) {
    // 注意初始化
    vector<int> s_first_index(128, 0);
    vector<int> t_first_index(128, 0);
    for (int i = 0; i < s.length(); ++i) {
      if (s_first_index[s[i]] != t_first_index[t[i]]) {
        return false;
      }
      s_first_index[s[i]] = t_first_index[t[i]] = i + 1;
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }
