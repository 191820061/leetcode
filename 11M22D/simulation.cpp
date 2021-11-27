#include <iostream>

using namespace std;

int main() {
    char result[62500];
    char c;
    int index = 0;
    while (cin >> c && c != 'E') {
        result[index++] = c;
    }
    if (index == 0) {
        cout << 0 << ":" << 0 << endl;
        printf("\n");
        cout << 0 << ":" << 0 << endl;
    }
    int a = 0;
    int b = 0;
    for (int i = 0; i < index; i++) {
        if (result[i] == 'W') {
            a++;
        } else if (result[i] == 'L') {
            b++;
        }
        if ((a == 11 || b == 11) && (a - b >= 2 || b - a >= 2)) {
            cout << a << ":" << b << endl;

            a = 0;
            b = 0;
        } else if ((a > 11 || b > 11) && (a - b >= 2 || b - a >= 2)) {
            cout << a << ":" << b << endl;
            a = 0;
            b = 0;
        }
        if (i + 1 == index) {
            cout << a << ":" << b << endl;
        }
    }
    printf("\n");
    a = 0;
    b = 0;
    for (int i = 0; i < index; i++) {
        if (result[i] == 'W') {
            a++;
        } else if (result[i] == 'L') {
            b++;
        }
        if ((a == 21 || b == 21) && (a - b >= 2 || b - a >= 2)) {
            cout << a << ":" << b << endl;
            a = 0;
            b = 0;
        } else if ((a > 21 || b > 21) && (a - b >= 2 || b - a >= 2)) {
            cout << a << ":" << b << endl;
            a = 0;
            b = 0;
        }
        if (i + 1 == index) {
            cout << a << ":" << b << endl;
        }
    }
}