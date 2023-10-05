#include <iostream>
#include <string>
#include <sstream>
#include <stack>

using namespace std;

// Function to split a string into words
void splitString(const string &s, string &first_word, string &second_word);

int main() {
    stack<string> stack;
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
                cout << stack.top() << endl;
                stack.pop();
            } else cout << "NULL" << endl;
        }
    }
    return 0;
}

// Function to split a string into words
void splitString(const string &s, string &first_word, string &second_word) {
    istringstream iss(s);
    iss >> first_word >> second_word;
}

