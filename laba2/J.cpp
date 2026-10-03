#include <iostream>
#include <algorithm>

using namespace std;

bool check(long long d, long long n, long long a, long long b, long long w, long long h) {
    long long A = a + 2*d;
    long long B = b + 2*d;

    if (A <= w && B <= h) {
        long long cols = w / A;
        long long rows = h / B;

        if (rows >= (n + cols - 1) / cols) return true;
    }

    if (B <= w && A <= h) {
        long long cols = w / B;
        long long rows = h / A;

        if (rows >= (n + cols - 1) / cols) return true;
    }
    return false;
}

int main() {
    long long n, a, b, w, h;
    if (!(cin >> n >> a >> b >> w >> h)) return 0;

    long long left = 0;
    long long right = max(w, h);
    long long d = 0;

    while (left <= right) {
        long long mid = left + (right - left) / 2;
        if (check(mid, n, a, b, w, h)){
            d = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    cout << d;
    return 0;
}