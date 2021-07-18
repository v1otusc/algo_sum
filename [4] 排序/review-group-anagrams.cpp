/*
 * @Description:
 *
 * 编写一种方法，对字符串数组进行排序，将所有变位词组合在一起。
 *
 * 变位词是指字母相同，但排列不同的字符串。
 *
 * @输入示例：
 *
 * ["eat", "tea", "tan", "ate", "nat", "bat"],
 *
 * @输出实例：
 *
 * [
     ["ate","eat","tea"],
     ["nat","tan"],
     ["bat"]
   ]
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
  vector<vector<string>> groupAnagrams(vector<string>& strs) {
    unordered_map<string, vector<string>> mp;
    for (auto& str : strs) {
      string key = str;
      sort(key.begin(), key.end());
      mp[key].push_back(str);
    }

    vector<vector<string>> ans;
    for (auto& m : mp) {
      ans.push_back(m.second);
    }
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
