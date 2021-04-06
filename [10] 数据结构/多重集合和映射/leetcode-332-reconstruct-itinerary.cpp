/*
 * @Description:
 *
 * 给定一个人坐过的一些飞机的起止机场,已知这个人从 JFK(肯尼迪国际机场)
 * 起飞,那么这个人是按什么顺序飞的；如果存在多种可能性,返回字母序最小的那种。
 *
 * @输入示例：
 *
 * [["MUC", "LHR"], ["JFK", "MUC"], ["SFO", "SJC"], ["LHR", "SFO"]]
 *
 * @输出实例：
 *
 * ["JFK", "MUC", "LHR", "SFO", "SJC"]
 *
 * @输入输出说明：
 *
 输入是一个二维字符串数组,表示多个起止机场对
 输出是一个一维字符串数组,表示飞行顺序。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 * 使用栈来恢复从终点到起点飞行的顺序，再将结果逆序得到从起点到终点的顺序
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<string> findItinerary(vector<vector<string>>& tickets) {
    vector<string> ans;
    if (tickets.empty()) {
      return ans;
    }
    // 其中键是起始机场，值是一个多重集合，表示对应的终止机场
    // 因为一个人可能坐过重复的线路,所以我们需要使用多重集合储存重复值。
    unordered_map<string, multiset<string>> hash;
    for (auto& ticket : tickets) {
      hash[ticket[0]].insert(ticket[1]);
    }
    stack<string> s;
    s.push("JFK");
    while (!s.empty()) {
      string start = s.top();
      
      if (hash[start].empty()) {
        ans.push_back(start);
        s.pop();
      } else {
        s.push(*(hash[start].begin()));
        hash[start].erase(hash[start].begin());
      }
    }
    reverse(ans.begin(), ans.end());
    return ans;
  }
};

int main(int argc, char const* argv[]) { return 0; }
