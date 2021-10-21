#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n == 1) {
        return s;
    }
    int state[n][n];
    for (int i = 0; i < n; i++) {
        state[i][i] = true;
    }

}

int main(int argc, char *argv[]) {

}