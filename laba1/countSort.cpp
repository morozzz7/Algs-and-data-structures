#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> countSort(vector<int>& arr) {
    if (arr.empty()) return arr;

    int min_val = arr[0];
    int max_val = arr[0];
    
    for (int num : arr) {
        if (num < min_val) min_val = num;
        if (num > max_val) max_val = num;
    }
    int len_count = max_val - min_val + 1;
    vector<int> count_arr(len_count, 0);
    vector<int> sorted_arr;


    for (int num : arr) {
        count_arr[num - min_val] += 1;
    }

    for (int i = 0; i < len_count; i++) {
        int count = count_arr[i];
        int actual_val = min_val + i;
        for (int j = 0; j < count; j++) {
            sorted_arr.push_back(actual_val);
        }
    }
    return sorted_arr;
}

int main() {
    string input;
    getline(cin, input);
    vector<int> arr;
    stringstream ss(input);
    int num;
    while (ss >> num) {
        arr.push_back(num);
    }

    vector<int> sorted_arr = countSort(arr);

    for (int i = 0; i < sorted_arr.size(); i++) {
        cout << sorted_arr[i];
        if (i < sorted_arr.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}