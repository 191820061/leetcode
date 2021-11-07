#include <iostream>
#include <vector>
#include <string>

using namespace std;

string longestCommonPrefix(vector<string> &strs) {
    if (strs.size() == 1) {
        return strs[0];
    }
    string same = strs[0];
    string result;
    for (int i = 1; i < strs.size(); i++) {
        result.clear();
        for (int j = 0; j < strs[i].size(); j++) {
            if (same[j] == strs[i][j]) {
                result += same[j];
            } else {
                break;
            }
        }
        same = result;
    }
    return result;
}

int main() {
    vector<string> strs{"dog","racecar","car"};
    cout<<longestCommonPrefix(strs)<<endl;
}