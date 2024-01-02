#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, k;//k la so vua load vao
    string c;
    cin >> n;
    vector<int> a(n, 0);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    while (c != "*") {
        cin >> c;
        if (c == "insert") {
            cin >> k;
            a.push_back(k);
        }
        if (c == "delete-max") {
            if (!a.empty()) {
                auto it = max_element(a.begin(), a.end());
                int max = *it;
                cout << max << endl;
                a.erase(it);
            } else cout << "Their is no element to delete!";
        }
    }
    return 0;
}