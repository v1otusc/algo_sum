/*
 * @Description:
 *
 * 给定 N 个课程和这些课程的前置必修课,求可以一次性上完所有课的顺序。
 *
 * @输入示例：
 *
 * numCourses = 4
 * prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
 *
 * @输出实例：
 *
 * [0, 1, 2, 3] 另一种可行的顺序是 [0, 2, 1, 3]
 *
 * @输入输出说明：
 *
 * 输入是一个正整数,表示课程数量,和一个二维矩阵,表示所有的有向边(如 [1,0] 表示上
 * 课程 1 之前必须先上课程 0)。输出是一个一维数组,表示拓扑排序结果。
 *
 * @限制条件：
 *
 * NULL
 *
 * @题目思路：
 *
 我们可以先建立一个邻接矩阵表示有向图,方便进行直接查找。这里注意我们将所有的边反向,
 使得如果课程 i 指向课程 j,那么课程 i 需要在课程 j
 前面先修完。这样更符合我们的直观理解。

 拓扑排序也可以被看成是广度优先搜索的一种情况:我们先遍历一遍所有节点,把入度为 0
 的节点(即没有前置课程要求)放在队列中。在每次从队列中获得节点时,我们将该节点放在目
 前排序的末尾,并且把它指向的课程的入度各减
 1;如果在这个过程中有课程的所有前置必修课 都已修完(即入度为 0)
 ,我们把这个节点加入队列中。当队列的节点都被处理完时,说明所有的
 节点都已经拍好序，或因图中存在循环而无法上完所有课程
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

class Solution {
 public:
  vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
    // 建立有向图
    vector<vector<int>> graph(numCourses, vector<int>{});
    vector<int> indegree(numCourses, 0);
    vector<int> res;
    for (const auto& prerequisite : prerequisites) {
      graph[prerequisite[1]].push_back(prerequisite[0]);
      // 建立每个节点的入度
      ++indegree[prerequisite[0]];
    }

    queue<int> q;
    for (int i = 0; i < indegree.size(); ++i) {
      if (!indegree[i]) {
        q.push(i);
      }
    }

    // 开始上不需要前置课程的课程
    while (!q.empty()) {
      int u = q.front();
      // 入度为 0，直接 push_back
      res.push_back(u);
      q.pop();
      for (auto v : graph[u]) {
        --indegree[v];
        // 已经上完前置课程了，push 进去相当于上课
        if (!indegree[v]) {
          q.push(v);
        }
      }
    }
    // 检查入度是否都是零了
    for (int i = 0; i < indegree.size(); ++i) {
      if (indegree[i]) {
        return vector<int>{};
      }
    }
    return res;
  }
};

int main(int argc, char const* argv[]) { return 0; }
