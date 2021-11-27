#include <iostream>

using namespace std;

int main() {
    char word[10000];
    char result[10000];
    int n = 0;
    int m = 0;
    int index = 0;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> word[index++];
        }
    }
    for (int i = 0; i < index; i++) {
        int value = 0;
        if (word[i] == '*') {
            result[i] = '*';
            continue;
        }
        if (i - 1 >= 0 && i % m != 0 && word[i - 1] == '*') {
            value++;
        }
        if (i + 1 < index && (i + 1) % m != 0 && word[i + 1] == '*') {
            value++;
        }
        if (i - m >= 0) {
            if (word[i - m] == '*') {
                value++;
            }
            if (i - m - 1 >= 0 && (i - m) % m != 0 && word[i - m - 1] == '*') {
                value++;
            }
            if (i - m + 1 >= 0 && (i - m + 1) % m != 0 && word[i - m + 1] == '*') {
                value++;
            }
        }
        if (i + m < index) {
            if (word[i + m] == '*') {
                value++;
            }
            if (i + m + 1 < index && (i + m + 1) % m != 0 && word[i + m + 1] == '*') {
                value++;
            }
            if (word[i + m - 1] == '*' && (i + m) % m != 0) {
                value++;
            }
        }
        result[i] = value + '0';
    }
    for (int i = 0; i < n; i++) {
        for (int j = m * i; j < m * (i + 1); j++) {
            printf("%c", result[j]);
        }
        printf("\n");
    }
}