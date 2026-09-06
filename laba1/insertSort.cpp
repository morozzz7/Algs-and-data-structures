#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> insertSort(vector<int>& arr) {
    if (arr.empty()) return arr;

    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j -= 1;
        }
        arr[j + 1] = key;
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

    insertSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}