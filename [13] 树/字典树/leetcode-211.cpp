/*
 * @Description:
 *
 * 
 *
 * @调用样例：
 *
 * 
 *
 * @限制条件：
 *
 *
 * @题目思路：
 * 
 * 字典数加上对点号的处理
 *
 * 详见代码
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;


struct TrieNode{
  vector<TrieNode*> child;
  // 是否是最后一个节点
  bool bend;
  TrieNode() : bend(false) { this->child = vector<TrieNode*>(26, nullptr); }
};

void insert(TrieNode* root, const string& word) {
  TrieNode* node = root;
  for (auto c : word) {
    if (node->child[c - 'a'] == nullptr) {
      node->child[c - 'a'] = new TrieNode();
    }
    node = node->child[c - 'a'];
  }
  node->bend = true;
}

class WordDictionary {
 public:
  WordDictionary() { trie = new TrieNode(); }

  void addWord(string word) { insert(trie, word); }

  bool search(string word) { return dfs(word, 0, trie); }

  bool dfs(const string& word, int index, TrieNode* node) {
    if (index == word.size()) return node->bend;

    char ch = word[index];
    if (ch >= 'a' && ch <= 'z') {
      TrieNode* child = node->child[ch - 'a'];
      if (child != nullptr && dfs(word, index + 1, child)) {
        return true;
      }
    } else if (ch == '.') {
      // 每个单词都试一试
      for (int i = 0; i < 26; ++i) {
        TrieNode* child = node->child[i];
        if (child != nullptr && dfs(word, index + 1, child)) {
          return true;
        }
      }
    }
    return false;
  }

 private:
  // 字典树根节点
  TrieNode* trie;
};

int main(int argc, char const* argv[]) { return 0; }
