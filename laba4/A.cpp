#include <iostream>
#include <vector>

using namespace std;

class MaxHeap {
private:
    vector<int> data;

public:
    MaxHeap(int capacity) {
        data.reserve(capacity);
    }

    void SiftUp(int i) {
        while (i > 0) {
            int parent = (i - 1) / 2;

            if (data[parent] >= data[i]) {
                break;
            }

            swap(data[parent], data[i]);
            i = parent;
        }
    }

    void Insert(int k) {
        data.push_back(k);
        SiftUp(static_cast<int>(data.size()) - 1);
    }

    void SiftDown(int i) {
        int n = static_cast<int>(data.size());

        while (true) {
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            int largest = i;

            if (left < n && data[left] > data[largest]) {
                largest = left;
            }

            if (right < n && data[right] > data[largest]) {
                largest = right;
            }

            if (largest == i) {
                break;
            }

            swap(data[i], data[largest]);
            i = largest;
        }
    }

    int Extract() {
        int maxValue = data[0];
        int last = static_cast<int>(data.size()) - 1;

        data[0] = data[last];
        data.pop_back();

        if (!data.empty()) {
            SiftDown(0);
        }

        return maxValue;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    MaxHeap heap(n);

    for (int i = 0; i < n; ++i) {
        int cmd;
        cin >> cmd;

        if (cmd == 0) {
            int k;
            cin >> k;
            heap.Insert(k);
        } else {
            cout << heap.Extract() << '\n';
        }
    }

    return 0;
}
