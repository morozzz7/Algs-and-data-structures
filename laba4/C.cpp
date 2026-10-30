#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> heap;

void SiftUp(int i) {
    while (i > 0) {
        int parent = (i - 1) / 2;
        if (heap[parent] <= heap[i]) break;
        swap(heap[parent], heap[i]);
        i = parent;
    }
}

void SiftDown(int i) {
    int n = static_cast<int>(heap.size());
    while (true) {
        int left  = 2 * i + 1;
        int right = 2 * i + 2;
        int smallest = i;

        if (left  < n && heap[left]  < heap[smallest]) smallest = left;
        if (right < n && heap[right] < heap[smallest]) smallest = right;

        if (smallest == i) break;

        swap(heap[i], heap[smallest]);
        i = smallest;
    }
}

int Extract() {
    int minValue = heap[0];
    heap[0] = heap.back();
    heap.pop_back();
    if (!heap.empty()) SiftDown(0);
    return minValue;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string cmd;
    while (cin >> cmd) {
        if (cmd == "CLEAR") {
            heap.clear();
        } else if (cmd == "ADD") {
            int n;
            cin >> n;
            heap.push_back(n);
            SiftUp(static_cast<int>(heap.size()) - 1);
        } else if (cmd == "EXTRACT") {
            if (heap.empty()) {
                cout << "CANNOT\n";
            } else {
                cout << Extract() << "\n";
            }
        }
    }
    return 0;
}