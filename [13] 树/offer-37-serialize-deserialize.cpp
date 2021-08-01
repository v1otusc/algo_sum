/*
 * @Description:
 *
 * 序列化与反序列化二叉树
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
 *
 *
 * @LastEditors: zzh
 * @LastEditTime: 2021-01-14 15:07:57
 * @FilePath: /algo_sum/template.cpp
 */

#include "bits/stdc++.h"

using namespace std;

struct TreeNode {
  int val;
  TreeNode* left;
  TreeNode* right;
  TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
 private:
  string null_ = "None";
  string sep_ = ",";

 public:
  // Encodes a tree to a single string.
  string serialize(TreeNode* root) {
    string ans{""};
    serialize_helper(root, ans);
    return ans;
  }

  // helper function
  void serialize_helper(TreeNode* root, string& s) {
    if (root == nullptr) {
      s += null_ + sep_;
      return;
    }
    s += to_string(root->val) + sep_;
    serialize_helper(root->left, s);
    serialize_helper(root->right, s);
  }

  // Decodes your encoded data to tree.
  TreeNode* deserialize(string data) {
    list<string> nodes;
    string str;
    for (auto& ch : data) {
      if (ch == ',') {
        nodes.push_back(str);
        str.clear();
      } else {
        str += ch;
      }
    }
    if (!str.empty()) {
      nodes.push_back(str);
      str.clear();
    }
    return deserialize_helper(nodes);
  }

  TreeNode* deserialize_helper(list<string>& nodes) {
    if (nodes.front() == "None") {
      nodes.erase(nodes.begin());
      return nullptr;
    }
    TreeNode* root = new TreeNode(stoi(nodes.front()));
    nodes.erase(nodes.begin());
    // 注意是先左后右
    root->left = deserialize_helper(nodes);
    root->right = deserialize_helper(nodes);
    return root;
  }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));

int main(int argc, char const* argv[]) {
  TreeNode* root;
  Codec ser, deser;
  TreeNode* ans = deser.deserialize(ser.serialize(root));
  return 0;
}
