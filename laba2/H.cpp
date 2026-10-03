#include <iostream>
#include <algorithm>

using namespace std;

bool check(long long mid, long long w, long long h, long long n) {
    return (mid / w) * (mid / h) >= n;
}

int main() {
    long long w, h, n;
    if (!(cin >> w >> h >> n)) return 0;

    long long left = 1;
    long long right = max(w, h) * n;
    long long dim = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid, w, h, n)) {
            dim = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << dim;
    return 0;
}