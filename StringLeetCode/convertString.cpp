#include <iostream>
#include <string>
#include <vector>

using namespace std;

string convert(string s, int numRows) {
    int n = (int) s.size();
    if (numRows == 1) {
        return s;
    }
    vector<string> result(min(numRows, n));
    bool goDown = true;
    int index = 0;
    for (char c: s) {
        result[index] += c;
        if (index == 0) {
            goDown = true;
        } else if (index == numRows - 1) {
            goDown = false;
        }
        index += goDown ? 1 : -1;
    }
    string returnString;
    for (int i = 0; i < min(numRows, n); i++) {
        returnString += result[i];
    }
    return returnString;
}

int main() {
    string word;
    int numRows;
    cin >> word >> numRows;
    cout << convert(word, numRows) << endl;
}