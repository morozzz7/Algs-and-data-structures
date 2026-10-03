#include <iostream>
#include <algorithm>

using namespace std;

bool check(long T, long remaining_copies, long x, long y) {
    return (T / x) + (T / y) >= remaining_copies;
}

int main() {
    long n, x, y;
    if (!(cin >> n >> x >> y)) return 0;

    int first_copy_time = min(x, y);
    long remaining_copies = n - 1;

    long left = 0;
    long right = remaining_copies * min(x, y);
    int additional_time = 0;

    while (left <= right) {
        long mid = left + (right - left) / 2;

        if (check(mid, remaining_copies, x, y)) {
            additional_time = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    cout << first_copy_time + additional_time << "\n";

    return 0;
}