#include "../../include/make-tree.h"
#include <queue>

std::vector<int> in_order {3, 2, 1, 4, 5, 7, 6};
std::vector<int> post_order {3, 1, 2, 5, 6, 7, 4};

// 参数依次为：中序的范围、后序的范围
TreeNode *
BuildTree(int L1, int R1, int L2, int R2)
{
    if (L1 > R1)
        return nullptr;

    int root_val = post_order[R2];
    int p = L1;
    while (in_order[p] != root_val)
        p++;
    int count = p-L1;
    TreeNode *root = new TreeNode(root_val);
    root->left = BuildTree(L1, L1+count-1, L2, L2+count-1);
    root->right = BuildTree(p+1, R1, L2+count, R2-1);
    return root;
}

// 层序遍历
void
LevelOrderTraverse(TreeNode *root)
{
    std::queue<TreeNode *> pq;
    int size;

    if (root == nullptr)
        return;

    pq.push(root);
    while (!pq.empty()) {
        size = pq.size();
        while (size != 0) {
            auto top = pq.front();
            std::cout << top->val << " ";
            pq.pop();
            if (top->left != nullptr) pq.push(top->left);
            if (top->right != nullptr) pq.push(top->right);
            --size;
        }
        std::cout << "\n";
    }
}

// 到目前为止的最优解和对应的权和
int best, best_sum=10000;

void
DFS(TreeNode *node, int sum)
{
    sum += node->val;
    if (node->left == nullptr && node->right == nullptr) {
        // 叶子
        if (sum < best_sum || (sum == best_sum && node->val < best)) {
            // 找出一个叶子使得它到根的路径的权和最小
            // 如果有多个解，则使该叶子本是的权最小
            // 每个叶子的权重都不同，且都是小于10000的正整数
            best = node->val;
            best_sum = sum;
        }
    }
    if (node->left != nullptr)
        DFS(node->left, sum);
    if (node->right != nullptr)
        DFS(node->right, sum);
}

int
main(int argc, char **argv)
{
    in_order = {7, 8, 11, 3, 5, 16, 12, 18};
    post_order = {8, 3, 11, 7, 16, 18, 12, 5};

    in_order = {255};
    post_order = {255};

    in_order = {3, 5, 7, 9, 4, 6};
    post_order = {3, 5, 9, 6, 4, 7};
    auto root = BuildTree(0, in_order.size()-1, 0, post_order.size()-1);
    LevelOrderTraverse(root);
    DFS(root, 0);
    std::cout << "best: " << best << std::endl;

    return 0;
}
