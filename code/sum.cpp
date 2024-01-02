#include<bits/stdc++.h>

using namespace std;

int main() {
    string num1;
    string num2;
    cin >> num1 >> num2;
    if (num1.length() > num2.length()) {
        num1.swap(num2);
    }
    auto n1 = num1.length();
    auto n2 = num2.length();
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());

    int carry = 0;
    string str;

    for (auto i = 0; i < n1; i++) {
        auto sum = (num1[i] - '0') + (num2[i] - '0') + carry;
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }


    for (auto i = n1; i < n2; i++) {
        auto sum = (num2[i] - '0') + carry;
        str.push_back(sum % 10 + '0');
        carry = sum / 10;
    }
    if (carry) {
        str.push_back(carry + '0');
    }

    reverse(str.begin(), str.end());

    cout << str << endl;
    return 0;
}