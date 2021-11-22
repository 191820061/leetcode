#include <iostream>
#include <cmath>

using namespace std;

string get_power(int n) {
    if (n == 2) {
        return "2";
    }
    if (n == 1) {
        return "2(0)";
    }
    if (n == 3) {
        return "2+2(0)";
    }
    if (n <= 0) {
        return "";
    }
    for (int i = 2; i <= 15; i++) {
        if (n < (int) pow(2.0, i)) {
            string value="2(" + get_power(i - 1) + ')' + "+" + get_power(n - (int) pow(2.0, i - 1));
            return value;
        } else if (n == (int) pow(2.0, i)) {
            string value="2(" + get_power(i) + ')';
            return value;
        }
    }
}

int main() {
    int n = 0;
    cin >> n;
    cout << get_power(n) << endl;
}