#include <iostream>
#include <vector>

using namespace std;

bool check(int Dist, const vector<int>& stalls, int K) {
    int count = 1;
    int last_position = stalls[0];

    for (size_t i = 1; i < stalls.size(); i++) {
        if (stalls[i] - last_position >= Dist) {
            count++;
            last_position = stalls[i];
        }
    }
    return count >= K;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> stalls(n);
    for (int i = 0; i < n; i++) {
        cin >> stalls[i];
    }

    int left = 1;                            
    int right = stalls[n - 1] - stalls[0];
    int ans = 0;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid, stalls, k)) {
            ans = mid;   
            left = mid + 1; 
        } else {
            right = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
