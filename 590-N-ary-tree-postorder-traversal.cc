#include <vector>
#include <stack>

struct Node {
    int val;
    std::vector<Node*> children;

    Node(int _val, std::vector<Node*> _children) :
        val(_val), children(_children) {  }
};

class Solution {
    public:
        std::vector<int> postorder(Node *root) {
            if (root == nullptr)
                return ret;
            else if (root->children.empty()) {
                ret.push_back(root->val);
                return ret;
            } else {
                for (int i = 0; i < root->children.size(); ++i) {
                    postorder(root->children[i]);
                }
            }

            return ret;
        }

        std::vector<int> ret;
};
