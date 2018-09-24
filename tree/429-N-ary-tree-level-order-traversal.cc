#include <vector>
#include <queue>

struct Node {
    int val;
    std::vector<Node*> children;

    Node(int _val, std::vector<Node*> _children) :
        val(_val), children(_children) {  }
};

class Solution {
    public:
        std::vector<std::vector<int>> levelOrder(Node *root) {
            if (root == nullptr)
                return ret;

            std::queue<Node*> q;
            q.push(root);

            while (!q.empty()) {
                std::vector<int> level;
                int sz = q.size();
                for (int i = 0; i < sz; ++i) {
                    Node *n = q.front();
                    q.pop();
                    level.push_back(n->val);
                    for (auto c : n->children) {
                        if (c != nullptr)
                            q.push(c);
                    }
                }
                ret.push_back(level);
            }

            return ret;
        }

        std::vector<std::vector<int>> ret;
};
