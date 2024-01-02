#include <bits/stdc++.h>

using namespace std;

int kSubsq(int n, int k, int m, vector<int> &a) {
    int count1 = 0;
    for (int i = 0; i < n - k; ++i) {
        if (m == (a[i] + a[i + 1] + a[i + 2])) {
//            cout<<a[i]<<" "<<a[i+1]<<" "<<a[i+2]<<endl;
            count1++;
        }
    }
    return count1;

}

int main() {
    int n, k, m;
    vector<int> a(n,0);
    cin >> n >> k >> m;
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }
    cout << kSubsq(n, k, m, a);
}
