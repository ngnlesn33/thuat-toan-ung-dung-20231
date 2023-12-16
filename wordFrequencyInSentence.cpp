#include <iostream>
#include <sstream>
#include <string>
#include <map>

using namespace std;

int main() {
    map<string, int> M;
    // Get the String
    string TEXT, str;
    while (getline(cin, TEXT) && !TEXT.empty()) {
        str += TEXT;
    }
    // process space
    istringstream iss(str);
    do {
        string subs;
        iss >> subs;
        if (!subs.empty()) {
            //use a temporary variable to store the result. Avoid performing the map
            //lookup multiple times -> Cost O(log n)
            int &count = M[subs];
            count++;
        }

    } while (iss);
    auto it = M.begin();
    while (it != M.end()) {
        cout << it->first << " " << it->second << endl;
        ++it;
    }

    return 0;
}
