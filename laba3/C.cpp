#include <iostream>
#include <stack>
#include <string>
#include <sstream>

using namespace std;

int main() {
    string line;
    getline(cin, line);
    
    istringstream iss(line);
    stack<int> st;
    string token;

    while (iss >> token) {
        if (token == "+" || token == "-" || token == "*") {
            int b = st.top(); st.pop();
            int a = st.top(); st.pop();
            int result;

        if (token == "+") {
            result = a + b;
        } else if (token == "-") {
            result = a - b;
        } else {
            result = a * b;
        }
        st.push(result);
        } else {
            st.push(stoi(token));
        }
    }
    cout << st.top() << endl;
    return 0;
}