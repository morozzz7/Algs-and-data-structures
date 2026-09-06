#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

string largest_number(vector<string>& parts) {
    if (parts.empty()) return "0";

    sort(parts.begin(), parts.end(), [](const string& a, const string& b){
        return a + b > b + a;
    });

    if (parts[0] == "0") return "0";

    string result = "";
    for (const string& part : parts) {
        result += part;
    }

    return result;
}

int main () {
    vector<string> parts;
    string part;

    while(cin >> part) {
        parts.push_back(part);
    }
    cout << largest_number(parts);
    return 0;
}