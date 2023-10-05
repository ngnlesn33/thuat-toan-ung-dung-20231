#include <iostream>
#include <string>
#include <sstream>
#include <stack>
#include <vector>

using namespace std;

void splitString(const std::string &s, std::string &first_word, std::string &second_word);

int main() {
    stack<string> stack;
    vector<string> v;
    // get string
    string line;
    // read a line from std::cin into line
    while (getline(cin, line) && !line.empty()) {
        string first_word, second_word;
        splitString(line, first_word, second_word);

        if (first_word == "PUSH") {
            stack.push(second_word);
        }
        if (first_word == "POP") {
            if (!stack.empty()) {
                v.insert(v.end(),stack.top());
                stack.pop();
            } else v.insert(v.end(),"NULL");
        }
    }
    for (const auto& x : v)
        cout << x << endl;
    return 0;
}

// Function to split a string into words
void splitString(const string &s, string &first_word, string &second_word) {
    istringstream iss(s);
    iss >> first_word >> second_word;
}
