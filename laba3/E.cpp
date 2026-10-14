#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Dequeue {
private:
    vector<int> items;

public:
    void push_front(int n) {
        items.insert(items.begin(), n);
        cout << "ok\n";
    }

    void push_back(int n) {
        items.push_back(n);
        cout << "ok\n";
    }

    void pop_front() {
        if (items.empty()) {
            cout << "error\n";
        } else {
            cout << items.front() << "\n";
            items.erase(items.begin());
        }
    }

    void pop_back() {
        if (items.empty()) {
            cout << "error\n";
        } else {
            cout << items.back() << "\n";
            items.pop_back();
        }
    }

    void front() {
        if (items.empty()) {
            cout << "error\n";
        } else {
            cout << items.front() << "\n";
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

    Dequeue deq;
    string command;

    while (cin >> command) {
        if (command == "push_front") {
            int n;
            cin >> n;
            deq.push_front(n);
        } 
        else if (command == "push_back") {
            int n;
            cin >> n;
            deq.push_back(n);
        }
        else if (command == "pop_front") {
            deq.pop_front();
        } 
        else if (command == "pop_back") {
            deq.pop_back();
        }
        else if (command == "front") {
            deq.front();
        } 
        else if (command == "back") {
            deq.back();
        }
        else if (command == "size") {
            deq.size();
        } 
        else if (command == "clear") {
            deq.clear();
        } 
        else if (command == "exit") {
            cout << "bye\n";
            break;
        }
    }

    return 0;
}