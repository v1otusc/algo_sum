/*
 * @Description:
 *
 *
 * 一个王国里住着国王、他的孩子们、他的孙子们等等。每一个时间点，这个家庭里有人出生也有人死亡。
 *
 * 继承顺序，实际上是前序遍历的顺序
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
 * 就是一个前序遍历的过程
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class ThroneInheritance {
 private:
  // string 表示一个人，vector<string> 中以列表的形式存放了这个人所有的孩子
  unordered_map<string, vector<string>> edges;
  unordered_set<string> dead;
  string king;

 public:
  ThroneInheritance(string kingName) : king(kingName) {}

  void birth(string parentName, string childName) {
    edges[parentName].push_back(childName);
  }

  void death(string name) { dead.insert(name); }

  void preorder(string& kingName, vector<string>& ans) {
    if (!dead.count(kingName)) ans.push_back(kingName);
    for (auto son : edges[kingName]) {
      preorder(son, ans);
    }
  }

  vector<string> getInheritanceOrder() {
    vector<string> ans;
    preorder(king, ans);
    return ans;
  }
};

/**
 * Your ThroneInheritance object will be instantiated and called as such:
 * ThroneInheritance* obj = new ThroneInheritance(kingName);
 * obj->birth(parentName,childName);
 * obj->death(name);
 * vector<string> param_3 = obj->getInheritanceOrder();
 */

int main(int argc, char const* argv[]) { return 0; }
