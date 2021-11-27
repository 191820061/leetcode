#include <iostream>

using namespace std;

bool find(const int* array, int index, int num) {
    for (int i = 0; i < index; i++) {
        if (array[i] == num) {
            return true;
        }
    }
    return false;
}

int mora(int n, int k, int(*p)[2]) {
    int count = 0;
    bool status[k];
    for (int i = 0; i < k; i++) {
        status[i] = true;
    }
    for (int i = 0; i < k; i++) {
        if (p[i][0] == p[i][1]) {
            count++;
            status[i] = false;
        }
        else if (p[i][0] > n || p[i][1] > n) {
            count++;
            status[i] = false;
        }
        else {
            int greaterNum[k];
            int index = 0;
            for (int j = 0; j < i; j++) {
                if (status[j]&&p[j][0] == p[i][1]) {
                    greaterNum[index++] = p[j][1];
                    if (p[j][1] == p[i][0]) {
                        count++;
                        !status[i];
                        break;
                    }
                }
                else if (status[j] && find(greaterNum, index, p[j][0])) {
                    greaterNum[index++] = p[j][1];
                    if (p[j][1] == p[i][0]) {
                        count++;
                        !status[i];
                        break;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    int n = 0;
    int k = 0;
    cin >> n;
    cin >> k;

    int array[k][2];
    for (int i = 0; i < k; i++) {
        cin >> array[i][0];
        cin >> array[i][1];
    }

    cout << mora(n, k, array);
}