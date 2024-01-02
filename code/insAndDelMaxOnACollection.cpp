#include<bits/stdc++.h>


using namespace std;


int main() {
    int lengthOfNums = 0;
    cin >> lengthOfNums;
    vector<int> v(lengthOfNums);
    vector<int> maxDel;
    for (int i = 0; i < lengthOfNums; ++i) {
        cin >> v[i];
    }
    // skip the first line
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    while (getline(cin, line) && !line.empty()) {
        if (line == "delete-max") {
            if (!v.empty()) {
                auto it = max_element(v.begin(), v.end());
                int max = *it;
                maxDel.push_back(max);
                v.erase(it);
            } else cout << "Their is no element to delete!";
        }

        string first_word;
        int second_num;
        istringstream iss(line);
        iss >> first_word >> second_num;
        if (first_word == "insert") {
            v.push_back(second_num);
        }
    }
    for(int num : maxDel){
        cout << num << endl;
    }
    return 0;
}

