#include <vector>
#include <iostream>

using namespace std;

int main() {
    int n = 3;
    int m = 4;
    std::vector<std::vector<int>> vec(n, std::vector<int>(m, 0));
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            std::cout << vec[i][j] << " ";
        }
        std::cout << std::endl;
    }
    cout << vec.size();
    cout << vec[0].size();
    return 0;
}