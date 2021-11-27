#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int partition(int *array, int low, int high) {
    int pivot = array[low];
    while (low < high) {
        while (low < high && array[high] >= pivot) {
            --high;
        }
        array[low] = array[high];
        while (low < high && array[low] <= pivot) {
            ++low;
        }
        array[high] = array[low];
    }
    array[low] = pivot;
    return low;
}

void quickSorted(int *array, int left, int right) {
    if (left < right) {
        int index = partition(array, left, right);
        quickSorted(array, left, index - 1);
        quickSorted(array, index + 1, right);
    }
}

int main() {
    int n;
    int k=0;
    vector<int> a;
    cin >> n>>k;
    int ele;
    for (int i = 0; i < n; i++) {
        cin >> ele;
        a.push_back(ele);
    }
    sort(a.begin(),a.end());
    for (int i = 0; i < n; i++) {
        cout<< a[i]<<" ";
    }
}