#include <iostream>
#include <vector>

using namespace std;

int bubbleSortCount(vector<int>& arr) {
    int n = arr.size();
    int count = 0;
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                count += 1;
            }
        }
        if (!swapped) {
            break;
        }
    }
    return count;
}

int main() {
    int n;
    if (!(cin >> n)) return 0; 
    
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int count = bubbleSortCount(arr);
    cout << count;
    
    return 0;
}