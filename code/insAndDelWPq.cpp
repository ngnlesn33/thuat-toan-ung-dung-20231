#include <bits/stdc++.h>

using namespace std;

int main() {
    int lengthOfNums = 0;
    cin >> lengthOfNums;
    // create a priority queue of integers
    priority_queue<int> pq;
    vector<int> maxDel;
    // read the numbers and insert them to the priority queue
    for (int i = 0; i < lengthOfNums; ++i) {
        int num;
        cin >> num;
        pq.push(num);
    }
    // skip the first line
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    string line;
    while (getline(cin, line) && !line.empty()) {
        if (line == "delete-max") {
            if (!pq.empty()) {
                // get the largest element from the top of the queue
                int max = pq.top();
                maxDel.push_back(max);
                // remove the largest element from the queue
                pq.pop();
            } else cout << "Their is no element to delete!";
        }

        string first_word;
        int second_num;
        istringstream iss(line);
        iss >> first_word >> second_num;
        if (first_word == "insert") {
            // insert a new element to the queue
            pq.push(second_num);
        }
    }
    for(auto const &num : maxDel){
        cout << num << endl;
    }
    return 0;
}
