#include <iostream>
#include <string>

using namespace std;

string longestPalindrome(string s) {
    int n = s.size();
    if (n==1){
        return s;
    }
    int status[n][n];
    for (int i = 0; i < n; i++) {
        status[i][i] = true;
    }
    int begin = 0;
    int maxLen = 1;
    for (int i = 1; i < n; i++) {
        for (int j = 0; j <= i; j++) {
            if (i - j >= 3) {
                if (s[j] == s[i]) {
                    status[j][i] = status[j + 1][i - 1];
                } else {
                    status[j][i] = false;
                }
            } else {
                if (s[j] == s[i]) {
                    status[j][i] = true;
                } else {
                    status[j][i] = false;
                }
            }
            if (status[j][i] && i - j + 1 > maxLen) {
                maxLen = i - j + 1;
                begin = j;
            }
        }
    }
    return s.substr(begin, maxLen);
}

int main(int argc, char *argv[]) {
    string word;
    cin >> word;
    cout << longestPalindrome(word) << endl;
}