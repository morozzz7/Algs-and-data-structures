#include <iostream>
#include <vector>

using namespace std;

void SiftDown(vector<int>& data, int i, int n) {

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

void HeapSort(vector<int>& arr) {
    int n = arr.size();

    for (int i = n / 2 - 1; i >= 0; i--) {
        SiftDown(arr, i, n);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        SiftDown(arr, 0, i);
        SiftDown(arr, 0, i);
    }
}

int main() {
    ios ::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    HeapSort(arr);
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " "; 
    }
    cout << "\n";
    return 0;
}