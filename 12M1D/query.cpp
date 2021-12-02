#include <iostream>

using namespace std;

int n;
int m;
int num[2000000];
int cache[200000];

int query(int number) {
    int left = 1;
    int right = n;
    if (number == num[left]) {
        return left;
    }
    while (left < right) {
        int mid = (left + right) / 2;
        if (num[mid] >= number) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    if (num[left] == number) {
        return left;
    }
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> num[i];
    }
    for (int i = 1; i <= m; i++) {
        cin >> cache[i];
    }
    for (int i = 1; i <= m; i++) {
        cout << query(cache[i]) << " ";
    }
}