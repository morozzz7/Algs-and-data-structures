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

int lowerBound(TreeNode* t, int key) {
    int res = -1;
    while (t) {
        if (t->val >= key) { res = t->val; t = t->left;  }
        else                t = t->right;
    }
    return res;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;

    TreeNode* root = nullptr;
    long long lastAnswer = 0;
    char prevOp = 0;                  
    const long long MOD = 1000000000;

    for (int k = 0; k < n; ++k) {
        char op;
        long long i;
        std::cin >> op >> i;

        if (op == '+') {
            long long val = i;
            if (prevOp == '?')
                {val = (i + lastAnswer) % MOD;}
            insert(root, val);
            prevOp = '+';
        } else {
            int ans = lowerBound(root, (int)i);
            std::cout << ans << '\n';
            lastAnswer = ans;
            prevOp = '?';
        }
    }

    return 0;
}