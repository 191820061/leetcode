#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int c;
vector<int> num;

int main() {
    cin >> n >> c;
    int element;
    for (int i = 0; i < n; i++) {
        cin >> element;
        num.push_back(element);
    }
    sort(num.begin(), num.end());
    int right = n - 1;
    int left = n - 2;
    long long count = 0;
    while (left >= 0) {
        if (num[right] - num[left] == c) {
            long long left_num = 1;
            long long right_num = 1;
            while (num[right - 1] == num[right]) {
                right--;
                right_num++;
            }
            while (num[left - 1] == num[left]) {
                left--;
                left_num++;
            }
            left--;
            right--;
            count += right_num * left_num;
        } else if (num[right] - num[left] > c) {
            right--;
        } else {
            left--;
        }
    }
    printf("%lld\n", count);
}