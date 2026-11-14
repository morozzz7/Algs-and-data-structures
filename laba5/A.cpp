#include <iostream>
#include <string>

struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    explicit TreeNode(int v) : val(v), left(nullptr), right(nullptr) {}
};

TreeNode* find(TreeNode* root, int val) {
    while (root) {
        if (val == root->val) return root;
        root = (val < root->val) ? root->left : root->right;
    }
    return nullptr;
}

bool insert(TreeNode*& root, int val) {
    TreeNode** cur = &root;
    while (*cur) {
        if (val == (*cur)->val) return false;
        cur = (val < (*cur)->val) ? &(*cur)->left : &(*cur)->right;
    }
    *cur = new TreeNode(val);
    return true;
}

bool erase(TreeNode*& root, int val) {
    TreeNode** cur = &root;
    while (*cur) {
        if (val == (*cur)->val) break;
        cur = (val < (*cur)->val) ? &(*cur)->left : &(*cur)->right;
    }
    if (!*cur) return false; 

    TreeNode* node = *cur;
    if (!node->left) {
        *cur = node->right;
        delete node;
    } else if (!node->right) {
        *cur = node->left;
        delete node;
    } else {
        TreeNode** maxPtr = &node->left;
        while ((*maxPtr)->right) maxPtr = &(*maxPtr)->right;
        TreeNode* maxNode = *maxPtr;
        node->val = maxNode->val;       
        *maxPtr = maxNode->left;        
        delete maxNode;
    }
    return true;
}

void print_tree(TreeNode* p, int level) {
    if (!p) return;
    print_tree(p->left, level + 1);
    for (int i = 0; i < level; ++i) std::cout << '.';
    std::cout << p->val << '\n';
    print_tree(p->right, level + 1);
}

void destroy(TreeNode* root) {
    if (!root) return;
    destroy(root->left);
    destroy(root->right);
    delete root;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    TreeNode* root = nullptr;
    std::string cmd;
    int n;

    while (std::cin >> cmd) {
        if (cmd == "ADD") {
            std::cin >> n;
            std::cout << (insert(root, n) ? "DONE" : "ALREADY") << '\n';
        } else if (cmd == "DELETE") {
            std::cin >> n;
            std::cout << (erase(root, n) ? "DONE" : "CANNOT") << '\n';
        } else if (cmd == "SEARCH") {
            std::cin >> n;
            std::cout << (find(root, n) ? "YES" : "NO") << '\n';
        } else if (cmd == "PRINTTREE") {
            print_tree(root, 0);
        }
    }

    destroy(root);
    return 0;
}