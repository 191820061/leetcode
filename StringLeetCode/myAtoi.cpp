#include <iostream>
#include <string>

using namespace std;

int myAtoi(string &s) {
    bool symbol = true;
    long long num = 0;
    for (char c: s) {
        if (c=='.'){
            break;
        }
        if (num==0&&isalpha(c)){
            break;
        }
        if (c == '-') {
            symbol = false;
        }else if(c=='+'){
            symbol = true;
        }
        if (isdigit(c)) {
            num = num * 10 + (c - '0');
            num = symbol ? min(num, (long long) INT_MAX) : min(num, -(long long) INT_MIN);
        }
    }
    return symbol ? (int)num : (int)-num;
}

int main(int argc, char *argv[]) {
    string word;
    getline(cin, word);
    int test = myAtoi(word);
    cout << test << endl;
}
