#include <iostream>
#include <cmath>

using namespace std;

int n;
int len;
int all[256];


int main() {
    cin >> n;
    len = (int) pow(2.0, n);
    for (int i = 1; i <= len; i++) {
        cin >> all[i];
    }
    int mid = (1 + len) / 2;
    int max = 0;
    int left_pos = 0;
    for (int i = 1; i <= mid; i++) {
        if (all[i] > max) {
            max = all[i];
            left_pos = i;
        }
    }
    int right_max = 0;
    int right_pos = 0;
    for (int i = mid + 1; i <= len; i++) {
        if (all[i] > right_max) {
            right_max = all[i];
            right_pos = i;
        }
    }
    int result = max > right_max ? right_pos : left_pos;
    cout << result << endl;
}