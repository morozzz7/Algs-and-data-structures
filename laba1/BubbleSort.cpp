#include <iostream>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

vector<int> bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] < arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        if (!swapped) {
            break;
        }
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

    bubbleSort(arr);

    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i];
        if (i < arr.size() - 1) {
            cout << " ";
        }
    }
    cout << endl;
    
    return 0;
}