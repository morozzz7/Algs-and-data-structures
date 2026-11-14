#include <iostream>
#include <algorithm>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int val) {
    TreeNode** cur = &root;
    while (*cur) {
        if (val == (*cur)->val) return;      
        cur = (val < (*cur)->val) ? &(*cur)->left : &(*cur)->right;
    }
    *cur = new TreeNode(val);
}

int height(TreeNode* node) {
    if (!node) return 0;
    return 1 + std::max(height(node->left), height(node->right));
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    TreeNode* root = nullptr;
    int x;
    while (std::cin >> x && x != 0) {
        insert(root, x);
    }

    std::cout << height(root) << "\n";
    return 0;
}



