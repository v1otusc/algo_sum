/*
 * @Description:
 *
 * 你有一个带有四个圆形拨轮的转盘锁。每个拨轮都有10个数字： '0', '1', '2', '3',
 * '4', '5', '6', '7', '8', '9' 。每个拨轮可以自由旋转：例如把 '9' 变为 '0'，'0'
 * 变为 '9' 。每次旋转都只能旋转一个拨轮的一位数字。
 *
 * 锁的初始数字为 '0000' ，一个代表四个拨轮的数字的字符串。
 *
 * 列表 deadends
 *包含了一组死亡数字，一旦拨轮的数字和列表里的任何一个元素相同，这个锁将会被永久锁定，无法再被旋转。
 *
 * 字符串 target
 *代表可以解锁的数字，需要给出解锁需要的最小旋转次数，如果无论如何不能解锁，返回-1
 *
 *
 * @输入示例：
 *
 * deadends = ["0201","0101","0102","1212","2002"], target = "0202"
 *
 * @输出实例：
 *
 * 6
 *
 * @输入输出说明：
 *
 * 可能的移动序列为 "0000" -> "1000" -> "1100" -> "1200" -> "1201" -> "1202" ->
 * "0202"。 注意 "0000" -> "0001" -> "0002" -> "0102" -> "0202"
 * 这样的序列是不能解锁的， 因为当拨动到 "0102" 时这个锁就会被锁定。
 *
 * @限制条件：
 *
 *
 *
 * @题目思路：
 *
 * BFS + 哈希表
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

// 将 string 第 i 位字符加 1
string plus_one(const string& s, int i) {
  string ret(s);
  if (ret[i] == '9') {
    ret[i] = '0';
  } else {
    ret[i] += 1;
  }
  return ret;
}

// 将 string 第 i 位字符减 1
string minus_one(const string& s, int i) {
  string ret(s);
  if (ret[i] == '0') {
    ret[i] = '9';
  } else {
    ret[i] -= 1;
  }
  return ret;
}

class Solution {
 public:
  int openLock(vector<string>& deadends, string target) {
    if (target == "0000") {
      return 0;
    }
    // 记录需要跳过的死亡密码
    unordered_set<string> deads;
    for (auto& str : deadends) {
      deads.insert(str);
    }
    if (deads.count(target)) {
      return -1;
    }
    // 记录已经穷举过的密码
    unordered_set<string> visited;
    queue<string> q;
    int step = 0;
    q.push("0000");
    visited.insert("0000");

    while (!q.empty()) {
      int sz = q.size();
      // 将当前队列中的节点进行扩散
      for (int i = 0; i < sz; ++i) {
        string cur = q.front();
        q.pop();

        if (deads.count(cur)) {
          continue;
        }
        if (cur == target) {
          return step;
        }

        // 将一个节点的未遍历节点相邻节点加入队列
        for (int j = 0; j < 4; ++j) {
          string up = plus_one(cur, j);
          if (!visited.count(up)) {
            q.push(up);
            visited.insert(up);
          }
          string down = minus_one(cur, j);
          if (!visited.count(down)) {
            q.push(down);
            visited.insert(down);
          }
        }
      }
      step++;
    }
    return -1;
  }
};

int main(int argc, char const* argv[]) {
  string target{"0202"};
  vector<string> deadends{"0201", "0101", "0102", "1212", "2002"};

  Solution s;
  cout << s.openLock(deadends, target) << endl;

  return 0;
}
