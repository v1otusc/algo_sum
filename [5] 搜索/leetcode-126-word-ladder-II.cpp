/*
 * @Description:
 *
 给定一个起始字符串和一个终止字符串，以及一个单词表，求是否可以将起始字符串每次改一个字符，,直到改成终止字符串,且所有中间的修改过程表示的字符串都可以在单词表里找到。
 直到改成终止字符串,且所有中间的修改若存在,输出需要修改次数最少的所有更改方式。
 *
 * @输入示例：
 *
 * beginWord = "hit" endWord = "cog"
 * wordList = ["hot","dot","dog","lot","log","cog"]
 *
 * @输出实例：
 *
 * [
    ["hit","hot","dot","dog","cog"],
    ["hit","hot","lot","log","cog"]
   ]
 *
 * @输入输出说明：
 *
 * - 如果不存在这样的转化序列，返回一个空列表
 * - 所有的单词具有相同的长度
 * - 所有的单词只由小写字母组成
 * - 字典中不存在重复的单词
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
我们可以把起始字符串、终止字符串、以及单词表里所有的字符串想象成节点。若两个字符
串只有一个字符不同,那么它们相连。因为题目需要输出修改次数最少的所有修改方式,因此我
们可以使用广度优先搜索,**求得起始节点到终止节点的最短距离。**

我们同时还可以使用一个小技巧，并不是直接从起始节点开始进行广度优先搜索，直到找到终止节点位为止，
而是从起始节点和终止节点分别进行广度优先搜索,每次只延展当前层节点数最少的那一端，这样我们可以减少搜索的总结点数
假设最短距离为 4,如果我们只从一端搜索 4 层，总遍历节点数为 1 + 2 + 4 + 8 + 16 =
31;而如果我们从两端各搜索两层,总遍历节点数最多只有 2 × （1 + 2 + 4）= 14

由于返回结果的要求，在搜素结束后，还需要通过回溯法来重建所有可能的路径
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  static void backtracking(const string& src, const string& dst,
                           unordered_map<string, vector<string>>& next,
                           vector<string>& path, vector<vector<string>>& ans) {
    if (src == dst) {
      ans.push_back(path);
      return;
    }

    for (const auto& s : next[src]) {
      path.push_back(s);
      backtracking(s, dst, next, path, ans);
      path.pop_back();
    }
  }

  static vector<vector<string>> findLadders(string beginWord, string endWord,
                                            vector<string>& wordList) {
    vector<vector<string>> ans;
    // unordered_set 查找起来更快
    unordered_set<string> dict;
    for (vector<string>::const_iterator it = wordList.cbegin();
         it != wordList.cend(); ++it) {
      dict.insert(*it);
    }
    // 考虑特殊情况
    if (!dict.count(endWord)) {
      return ans;
    }
    dict.erase(beginWord);
    dict.erase(endWord);
    unordered_set<string> q1{beginWord};
    unordered_set<string> q2{endWord};
    unordered_map<string, vector<string>> next;
    bool reversed = false;
    bool found = false;

    while (!q1.empty()) {
      // 表示树结构延展的当前层
      unordered_set<string> q;
      for (auto& w : q1) {
        string s = w;
        for (size_t i = 0; i < s.size(); i++) {
          // 保存当前状态
          char ch = s[i];
          for (int j = 0; j < 26; j++) {
            // 从 26 个字母中挑一个，替换单词中的一个字母
            s[i] = j + 'a';
            if (q2.count(s)) {
              // 判断是否从尾端搜索
              reversed ? next[s].push_back(w) : next[w].push_back(s);
              found = true;
            }
            // 用来记录 dict 中仅替换指定单词中一个字母的单词的集合
            if (dict.count(s)) {
              reversed ? next[s].push_back(w) : next[w].push_back(s);
              q.insert(s);
            }
          }
          // 恢复之前的状态
          s[i] = ch;
        }
      }
      if (found) {
        break;
      }

      for (const auto& w : q) {
        dict.erase(w);
      }

      if (q.size() <= q2.size()) {
        q1 = q;
      } else {
        reversed = !reversed;
        q1 = q2;
        q2 = q;
      }
    }

    if (found) {
      vector<string> path = {beginWord};
      backtracking(beginWord, endWord, next, path, ans);
    }

    return ans;
  }
};

int main(int argc, char const* argv[]) {
  string beginWord = "hit";
  string endWord = "cog";
  vector<string> wordList{"hot", "dot", "dog", "lot", "log", "cog"};
  auto ans = Solution::findLadders(beginWord, endWord, wordList);
  for (auto& i : ans) {
    for (auto& j : i) {
      cout << j << " ";
    }
    cout << endl;
  }
  return 0;
}