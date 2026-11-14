#include <iostream>

struct TreeNode {
    int val;
    int count;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int v) : val(v), count(1), left(nullptr), right(nullptr) {}
};

void insert(TreeNode*& root, int val) {
    TreeNode** cur = &root;
    while (*cur) {
        if (val == (*cur)->val) {
            (*cur)->count++;          
            return;
        }
        cur = (val < (*cur)->val) ? &(*cur)->left : &(*cur)->right;
    }
    *cur = new TreeNode(val);         
}

void inorder(TreeNode* node) {
    if (!node) return;
    inorder(node->left);
    std::cout << node->val << ' ' << node->count << '\n';
    inorder(node->right);
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    TreeNode* root = nullptr;
    int x;
    while (std::cin >> x && x != 0) insert(root, x);

    inorder(root);
    return 0;
}