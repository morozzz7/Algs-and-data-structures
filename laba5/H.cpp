#include <iostream>
#include <vector>

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

void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    if ((node->left && !node->right) || (!node->left && node->right)) {
    std::cout << node->val << ' ';
    }
    inorder(node->right);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    TreeNode* root = nullptr;
    int x;
    while (std::cin >> x && x != 0) {
        insert(root, x);
    }

    inorder(root);
    return 0;
}



