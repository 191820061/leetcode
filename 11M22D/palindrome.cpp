#include <iostream>
#include <cmath>
#include <string>
using namespace std;

string get_reverse(string &s) {
    string result;
    for (int i = s.size() - 1; i >= 0; i--) {
        result += s[i];
    }
    return result;
}

int char_int(char value) {
    if (value >= '0' && value <= '9') {
        return value - '0';
    } else {
        switch (value) {
            case 'A':
                return 10;
            case 'B':
                return 11;
            case 'C':
                return 12;
            case 'D':
                return 13;
            case 'E':
                return 14;
            case 'F':
                return 15;
        }
    }
    return -1;
}

char int_char(int value) {
    if (value >= 0 && value <= 9) {
        return value + '0';
    } else {
        switch (value) {
            case 10:
                return 'A';
            case 11:
                return 'B';
            case 12:
                return 'C';
            case 13:
                return 'D';
            case 14:
                return 'E';
            case 15:
                return 'F';
        }
    }
    return char();
}

bool isPalindrome(string &s) {
    int left = 0;
    int right = s.size() - 1;
    while (right - left > 0) {
        if (s[left++] != s[right--]) {
            return false;
        }
    }
    return true;
}

void string_add(string &s, int n) {
    string reverse = get_reverse(s);
    string result;
    int carry = 0;
    for (int i = s.size() - 1; i >= 0; i--) {
        int cache = char_int(s[i]) + char_int(reverse[i]) + carry;
        if (cache >= n) {
            result = int_char(cache - n) + result;
            carry = 1;
        } else {
            result = int_char(cache) + result;
            carry = 0;
        }
    }
    if (carry == 1) {
        result = '1' + result;
    }
    s = result;
}

int main() {
    int n;
    string m;
    cin >> n >> m;
    for (int i = 1; i <= 30; i++) {
        string_add(m, n);
        if (isPalindrome(m)) {
            cout << "STEP=" << i << endl;
            return 0;
        }
    }
    cout << "Impossible!" << endl;
}