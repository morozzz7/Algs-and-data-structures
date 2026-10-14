#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    vector<char> stack;
    bool ans = true;

    for (char c : s) {
        if (c != '(' && c != '{' && c != '[' && 
            c != ')' && c != '}' && c != ']') {
            continue;
        }

        if (c == '(' || c == '{' || c == '[') {
            stack.push_back(c);
            continue;
        }

        if (!stack.empty() && 
            ((c == ')' && stack.back() == '(') ||
             (c == ']' && stack.back() == '[') ||
             (c == '}' && stack.back() == '{'))) {
            stack.pop_back();
        } else {
            ans = false;
            break;
        }
    }

    if (!stack.empty()) {
        ans = false;
    }

    cout << (ans ? "yes" : "no") << endl;

    return 0;
}

