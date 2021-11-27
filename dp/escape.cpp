#include <iostream>
#include <cmath>

using namespace std;


int main() {
    int m = 0;
    int s = 0;
    int t = 0;
    scanf("%d %d %d", &m, &s, &t);
    int value = 0;
    for (int i = 1; i <= t; i++) {
        if (m >= 10) {
            m -= 10;
            value += 60;
        } else if ((ceil(2.5 - (m / 4.0))+1) * 17 + value >= s || ceil(2.5 - (m / 4.0)) >= (t - i + 1)) {
            value += 17;
        } else {
            m += 4;
        }
        if (value >= s) {
            cout << "Yes" << endl;
            cout << i << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    cout << value << endl;

}