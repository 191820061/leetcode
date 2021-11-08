#include <iostream>
#include <vector>
using namespace std;

vector <string> letterCombinations(string digits) {
    if (digits.empty()){
        return {};
    }
    string first=digits.substr(0,1);
    vector<string> rest=letterCombinations(digits.substr(1,digits.size()-1));
}

int main() {

}