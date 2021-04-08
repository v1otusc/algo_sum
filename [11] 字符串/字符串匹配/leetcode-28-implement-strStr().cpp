/*
 * @Description:
 *
 * 判断一个字符串是不是另一个字符串的子字符串，并返回其位置
 *
 * @输入示例：
 *
 * haystack = "hello", needle = "ll"
 *
 * @输出实例：
 *
 * truen
 *
 * @输入输出说明：
 *
 输入一个母字符串和一个子字符串,输出一个整数,表示子字符串在母字符串的位置,若不
 存在则返回-1。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * KMP 算法
 *
 * 当 needle 是空字符串时，我们应当返回什么值呢？这是一个在面试中很好的问题。
 *
 * 对于本题而言，当 needle 是空字符串时我们应当返回 0 。这与C语言的 strstr()
 * 以及 Java的 indexOf() 定义相符。
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  
};

int main(int argc, char const* argv[]) { return 0; }
