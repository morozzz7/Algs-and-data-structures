#include <iostream>
#include <vector>

using namespace std;

bool check(int L, const vector<int>& ropes, int K) {
    if (L == 0) return true;
    
    int count = 0;
    for (int rope : ropes) {
        count += rope / L;
    }
    return count >= K;
}

int main() {
    int n, k;
    if (!(cin >> n >> k)) return 0;

    vector<int> ropes(n);
    for (int i = 0; i < n; i++) {
        cin >> ropes[i];
    }

    int left = 0;                
    int right = 10000000;        
    int ans = 0;                 

    while (left <= right) {
        int mid = (left + right) / 2;

        if (check(mid, ropes, k)) {
            ans = mid;       
            left = mid + 1;  
        } else {
            right = mid - 1;
        }
    }

    cout << ans << "\n";

    return 0;
}
