#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Stack {
private:
    vector<int> items;

public:
    void push(int n) {
        items.push_back(n);
        cout << "ok\n";
    }

    void pop() {
        if (items.empty()) {
            cout << "error\n";
        } else {
            cout << items.back() << "\n";
            items.pop_back();
        }
    }

    void back() {
        if (items.empty()) {
            cout << "error\n";
        } else {
            cout << items.back() << "\n";
        }
    }

    void size() {
        cout << items.size() << "\n";
    }

    void clear() {
        items.clear();
        cout << "ok\n";
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    Stack s;
    string command;

    while (cin >> command) {
        if (command == "push") {
            int n;
            cin >> n;
            s.push(n);
        } 
        else if (command == "pop") {
            s.pop();
        } 
        else if (command == "back") {
            s.back();
        } 
        else if (command == "size") {
            s.size();
        } 
        else if (command == "clear") {
            s.clear();
        } 
        else if (command == "exit") {
            cout << "bye\n";
            break;
        }
    }

    return 0;
}