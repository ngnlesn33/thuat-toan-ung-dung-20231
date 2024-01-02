#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;
    priority_queue<int> nums;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;
        nums.push(num);
    }
    string c;
    while (c != "*") {
        cin >> c;
        if (c == "insert") {
            int k;
            cin >> k;
            nums.push(k);
        }
        if (c == "delete-max") {
            if (!nums.empty()) {
                cout << nums.top() << endl;
                nums.pop();
            } else cout << "Their is no element to delete!" << endl;
        }
    }
}