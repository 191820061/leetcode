#include <iostream>
#include <string>

using namespace std;

int lengthOfLongestSubstring(string s) {
    if (s.size() <= 1) {
        return s.size();
    }
    int left = 0;
    int right = 1;
    int max = 0;
    while (right < s.size()) {
        for (int i = left; i < right; i++) {
            if (s[right] == s[i]) {
                int len = right - left;
                max = len > max ? len : max;
                left = i + 1;
                break;
            }
        }
        right++;
    }
    max = right - left > max ? right - left : max;
    return max;
}

int main(int argc, char *argv[]) {
    string word;
    cin >> word;
    cout << lengthOfLongestSubstring(word);
}