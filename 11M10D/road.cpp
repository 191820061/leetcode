#include <iostream>

using namespace std;

int find(int *array, int x) {
    while (array[x] != x) {
        x = array[x];
    }
    return x;
}

void merge(int *array, int x, int y, int n) {

    if (array[x] == x && array[y] == y) {
        array[y] = x;
    } else if (array[x] == x) {
        int y_parent = find(array, y);
        array[x] = y_parent;
    } else if (array[y] == y) {
        int x_parent = find(array, x);
        array[y] = x_parent;
    } else {
        int y_parent = find(array, y);
        int x_parent = find(array, x);
        array[y_parent] = x_parent;
    }
}

int get_set_num(int *array, int n) {
    int num = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] == i) {
            num++;
        }
    }
    return num;
}


int main() {
    int n = 0;
    int road_num = 0;
    cin >> n >> road_num;
    int array[n + 1];
    for (int i = 0; i < n + 1; i++) {
        array[i] = i;
    }
    int x = 0;
    int y = 0;
    for (int i = 0; i < road_num; i++) {
        cin >> x >> y;
        merge(array, x, y, n + 1);
    }
    printf("%d\n", get_set_num(array, n + 1) - 2);
}