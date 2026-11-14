#include <iostream>

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

int secondMax(TreeNode* root) {
    TreeNode* parent = nullptr;
    TreeNode* cur = root;

    while (cur->right) {
        parent = cur;
        cur = cur->right;
    }

    if (cur->left) {
        cur = cur->left;
        while (cur->right) {
            cur = cur->right;
        }
        return cur->val;
    }

    return parent->val;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    TreeNode* root = nullptr;
    int x;
    while (std::cin >> x && x != 0) {
        insert(root, x);
    }

    std::cout << secondMax(root) << "\n";
    return 0;
}



