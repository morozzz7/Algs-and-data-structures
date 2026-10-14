#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Queue {
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
            cout << items.front() << "\n";
            items.erase(items.begin());
        }
    }

    void front() {
        if (items.empty()) {
            cout << "error\n";
        } else {
            cout << items.front() << "\n";
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

    Queue q;
    string command;

    while (cin >> command) {
        if (command == "push") {
            int n;
            cin >> n;
            q.push(n);
        } 
        else if (command == "pop") {
            q.pop();
        } 
        else if (command == "front") {
            q.front();
        } 
        else if (command == "size") {
            q.size();
        } 
        else if (command == "clear") {
            q.clear();
        } 
        else if (command == "exit") {
            cout << "bye\n";
            break;
        }
    }

    return 0;
}