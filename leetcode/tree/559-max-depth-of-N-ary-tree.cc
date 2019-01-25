#include <vector>

class Node {
    public:
        int val;
        std::vector<Node*> children;
        Node() {  }
        Node(int _val, std::vector<Node*> _children) :
            val(_val), children(_children) {  }
};

class Solutions {
    public:
        int maxDepth(Node *root) {
            if (root == nullptr)
                return 0;
            else if (root->children.empty())
                return 1;
            else
                return 1+maxChildDepth(&(root->children));
        }

        int maxChildDepth(std::vector<Node*> *children) {
            int max = 0;
            for (auto it = children->begin(); it != children->end(); ++it) {
                int d = maxDepth(*it);
                if (d > max)
                    max = d;
            }

            return max;
        }

};

