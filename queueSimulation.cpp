#include<iostream>
#include <sstream>
#include <queue>


using namespace std;

void splitString(string &s, string &first_word, string &second_word);

using namespace std;

int main() {
    queue<string> q;
    vector<string> v;
    string line;
    while (getline(cin, line) && !line.empty()) {
        string first_word, second_word;
        splitString(line, first_word, second_word);

        if (first_word == "PUSH") {
            q.push(second_word);
        }
        if (first_word == "POP") {
            if (!q.empty()) {
                v.insert(v.end(), q.front());
                q.pop();
            } else v.insert(v.end(), "NULL");
        }
    }
    for (const auto &x: v)
        cout << x << endl;
    return 0;
}

void splitString(string &s, string &first_word, string &second_word) {
    istringstream iss(s);
    iss >> first_word >> second_word;
}
