// Author: btjanaka (Bryon Tjanaka)
// Problem: (LeetCode) 590
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/
class Solution {
 public:
  vector<int> postorder(Node* root) {
    vector<int> res;
    stack<pair<Node*, bool>> s;  // node, visited_yet
    if (root) s.push({root, false});
    while (!s.empty()) {
      Node* cur;
      bool visited;
      tie(cur, visited) = s.top();
      s.pop();
      if (visited) {
        res.push_back(cur->val);
      } else {
        s.push({cur, true});
        for (int i = cur->children.size() - 1; i >= 0; --i) {
          if (cur->children[i]) s.push({cur->children[i], false});
        }
      }
    }
    return res;
  }
};