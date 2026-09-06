#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> SelectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int max_ind = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] > arr[max_ind]) {
                max_ind = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[max_ind];
        arr[max_ind] = temp;
    }
    return arr;
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

    SelectionSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}