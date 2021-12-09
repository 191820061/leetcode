#include <iostream>
#include <cmath>

using namespace std;

int n;
int t;
int array[50005];

int main() {
    cin >> n >> t;
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    int left = 1;
    int right = array[n];
    while (left < right) {
        int mid = (left + right) / 2;
        int result = 0;
        for (int i = 1; i <= n; i++) {
            result += ceil((double) array[i] / mid);
        }
        if (result > t) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    cout << right << endl;
}