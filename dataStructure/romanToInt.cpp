#include <iostream>
#include <string>

using namespace std;

int romanToInt(const string &s) {
    int result = 0;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'I' && s[i + 1] != 'V' && s[i + 1] != 'X') {
            result += 1;
        } else if (s[i] == 'I' && s[i + 1] == 'V') {
            result += 4;
            i++;
        } else if (s[i] == 'I' && s[i + 1] == 'X') {
            result += 9;
            i++;
        } else if (s[i] == 'V') {
            result += 5;
        } else if (s[i] == 'X' && s[i + 1] != 'L' && s[i + 1] != 'C') {
            result += 10;
        } else if (s[i] == 'X' && s[i + 1] == 'L') {
            result += 40;
            i++;
        } else if (s[i] == 'X' && s[i + 1] == 'C') {
            result += 90;
            i++;
        } else if (s[i] == 'L') {
            result += 50;
        } else if (s[i] == 'C' && s[i + 1] != 'D' && s[i + 1] != 'M') {
            result += 100;
        } else if (s[i] == 'C' && s[i + 1] == 'D') {
            result += 400;
            i++;
        } else if (s[i] == 'C' && s[i + 1] == 'M') {
            result += 900;
            i++;
        } else if (s[i] == 'D') {
            result += 500;
        } else if (s[i] == 'M') {
            result += 1000;
        }
    }
    return result;
}

int main() {
    cout << romanToInt("MCMXCIV") << endl;
}