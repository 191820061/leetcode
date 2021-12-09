#include <iostream>

using namespace std;

int n;
int m;
int city_people[10000005];

void merge(int *array, int start, int mid, int end) {
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int S[n1];
    int E[n2];

    for (int i = 0; i < n1; i++) {
        S[i] = array[start + i];
    }
    for (int i = 0; i < n2; i++) {
        E[i] = array[mid + 1 + i];
    }
    int i = 0;
    int j = 0;
    for (int k = start; k <= end; k++) {
        if (i >= n1 || j >= n2) {
            if (i >= n1) {
                array[k] = E[j];
                j++;
            } else {
                array[k] = S[i];
                i++;
            }
        } else {
            if (S[i] < E[j]) {
                array[k] = S[i];
                i++;
            } else {
                array[k] = E[j];
                j++;
            }
        }
    }
}

void mergeSort(int *array, int start, int end) {
    if (start < end) {
        int mid = (end + start) / 2;
        mergeSort(array, start, mid);
        mergeSort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

int main() {
    cin >> m >> n;
    for (int i = 1; i <= n; i++) {
        cin >> city_people[i];
    }
    mergeSort(city_people, 1, n);
    cout << city_people[n - m + 1] << endl;
}