#include <vector>

struct Node {
    int val;
    std::vector<Node*> children;

    Node(int _val, std::vector<Node*> _children) :
        val(_val), children(_children) {  }
};

class Solution {
    public:
        std::vector<int> preorder(Node *root) {
            if (root == nullptr)
                return ret;
            else if (root->children.empty()) {
                ret.push_back(root->val);
                return ret;
            } else {
                ret.push_back(root->val);
                for (auto it = root->children.cbegin(); it != root->children.cend(); ++it)
                    preorder(*it);
            }
            return ret;
        }

        std::vector<int> ret;
};
