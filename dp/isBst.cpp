#include <bits/stdc++.h>

using namespace std;


bool isBst(int *array, int begin, int end) {
    if (begin==end){
        return true;
    }
    if (begin > end) {
        return false;
    }
    int top_value = array[end - 1];
    int right = -1;
    for (int i = begin; i < end - 1; i++) {
        if (array[i] > top_value) {
            right = i;
        }
        if (right != -1 && i > right && array[i] < top_value) {
            return false;
        }
    }
    if (right == -1) {
        return isBst(array, begin, end - 1);
    } else {
        return isBst(array, begin, right - 1) && isBst(array, right, end - 1);
    }
}

int main() {
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    cout << isBst(array, 0, n) << endl;
}