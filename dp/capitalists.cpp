#include <iostream>
#include <algorithm>

using namespace std;
int n;
int m;
long long array[1000001];
long long max_value;

void get_max_value() {
    long long max = array[1];
    for (int i = 1; i <= n; i++) {
        if (array[i]>max){
            max =array[i];
        }
    }
    max_value=max;
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        cin >> array[i];
    }
    get_max_value();
    long long result = 0;
    long long min_value = 0;
    while (min_value < max_value) {
        long long middle_value = (max_value + min_value) / 2;
        result = 0;
        for (int j = 1; j <= n; j++) {
            if (array[j] - middle_value > 0) {
                result += array[j] - middle_value;
            }
        }
        if (result < m) {
            if (max_value == middle_value) {
                cout << max_value << endl;
                break;
            }
            max_value = middle_value;
        } else {
            if (min_value == middle_value) {
                cout << min_value << endl;
                break;
            }
            min_value = middle_value;
        }
    }
}

