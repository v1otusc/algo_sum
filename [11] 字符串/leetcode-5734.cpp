/*
 * @Description:
 *
 * 全字母句 指包含英语字母表中每个字母至少一次的句子。
 * 给你一个仅由小写英文字母组成的字符串 sentence ，请你判断 sentence 是否为
 * 全字母句 。
 * 如果是，返回 true ；否则，返回 false 。
 *
 * @输入示例：
 *
 * sentence = "thequickbrownfoxjumpsoverthelazydog"
 *
 * @输出实例：
 *
 * true
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * 没什么好说的
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  bool checkIfPangram(string sentence) {
    vector<bool> letters(26,false);
    auto it = letters.begin();
    for (int i = 0; i < sentence.size(); ++i) {
      int c = sentence[i] - 'a';
      *(it + c) = true;
    }
    for (auto it :letters) {
      if (it == false) {
        return false;
      }
    }
    return true;
  }
};

int main(int argc, char const* argv[]) { return 0; }